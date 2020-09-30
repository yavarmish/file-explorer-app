// require node module 
const http=require('http');

// file imports
const respond=require('./lib/respond');

// connection settings
const port=process.env.PORT||3000;

// create server
const server=http.createServer(respond);

// listen to requests
server.listen(port,()=>{
    console.log(`listening on port: ${port}`);
})