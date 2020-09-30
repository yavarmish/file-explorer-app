const url = require('url');
const path = require('path');
const fs = require('fs');
const buildBreadCrumb = require('./breadcrumb');
const buildMainContent = require('./mainContent');
const getMimeType = require('./getMimeType');


const staticBasePath = path.join(__dirname, '..', 'static');
const respond = (request, response) => {
    // decode pathname 

    // find static path

    let pathname = url.parse(request.url, true).pathname;

    if (pathname === '/favicon.ico')
        return false;

    pathname = (decodeURIComponent(pathname));

    const fullStaticPath = path.join(staticBasePath, pathname);
    // console.log(fullStaticPath);
    if (!fs.existsSync(fullStaticPath)) {
        console.log(`${fullStaticPath} does not exists`);
        response.write('404:File not Found');
        response.end();
        return false;
    }

    let stats;
    try {

        stats = fs.lstatSync(fullStaticPath);
    }
    catch (err) {
        console.log(`lstatSync failed error:${err}`);
    }
    if (stats.isDirectory()) {
        let data = fs.readFileSync(path.join(staticBasePath, 'project_files/index.html'), 'utf-8');
        //change title of the page
        let pathElements = pathname.split('/').reverse();
        pathElements = pathElements.filter(element => element !== '');
        let folderName = pathElements[0];
        // console.log(folderName);
        if (folderName === undefined)
            folderName = 'Home';
        data = data.replace('page_title', folderName);
        // console.log(data);

        //build breadcrumb
        const breadcrumb = buildBreadCrumb(pathname);
        data = data.replace('pathname', breadcrumb);

        const mainContent = buildMainContent(fullStaticPath, pathname);
        data = data.replace('mainContent', mainContent);


        response.statusCode = 200;
        response.write(data);
        return response.end();


    }

    if (!stats.isFile()) {
        response.statusCode = 401;
        response.write('401: Access Denied!');
        return response.end();
    }

    let fileDetails = {};
    fileDetails.extname = path.extname(fullStaticPath);
    let stat;
    try {
        stat = fs.statSync(fullStaticPath);
    } catch (err) {
        console.log(`error:${err}`);
    }

    fileDetails.size = stat.size;

    getMimeType(fileDetails.extname).then(mime => {
        let head = {};
        let options = {};
        let statusCode = 200;


        head['Content-Type'] = mime;

        if (fileDetails.extname === '.pdf') {
            head['Content-Disposition'] = 'inline';
        }

        if (RegExp('audio').test(mime) || RegExp('video').test(mime)) {
            head['Accept-Ranges'] = 'bytes';
            const range = request.headers.range;
            // console.log(`range:${range}`);
            if (range) {


                const start_end = range.replace(/bytes=/, "").split('-');
                const start = parseInt(start_end[0]);
                const end = (start_end[1]) ? parseInt(start_end[1]) : fileDetails.size - 1;



                head['Content-Range'] = `bytes ${start}-${end}/${fileDetails.size}`;

                head['Content-Length'] = end - start + 1;
                statusCode = 206;

                options = { start, end };
            }




        }
        // fs.promises.readFile(fullStaticPath,'utf-8',)
        //     .then((data) => {

        //             response.writeHead(statusCode, Head);
        //             response.write(data);
        //             return response.end();


        //     })
        //     .catch(error=>{
        //         response.statusCode = 404;
        //         response.write(`404:File reading error,${error}`);
        //         return response.end();
        //     });

        const fileStream = fs.createReadStream(fullStaticPath, options);
        response.writeHead(statusCode, head);
        fileStream.pipe(response);

        fileStream.on('close', () => {
            return response.end();
        });

        fileStream.on('error', error => {
            response.statusCode = 404;
            response.write(`404:File Streaming error,${error}`);

            return response.end();
        });




    })
        .catch(err => {
            response.statusCode = 500;
            response.write('500: Internal Server Error');
            return response.end();
        })



}

module.exports = respond;