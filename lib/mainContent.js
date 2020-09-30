const fs = require("fs");
const path = require('path');

const calculateSizeD = require('./calculateSizeD');
const calculateSizeF = require('./calculateSizeF');


const buildMainContent = (fullStaticPath, pathname) => {
    let mainContent = '';
    let items;
    try {
        items = fs.readdirSync(fullStaticPath);

    } catch (err) {
        return `<div class="alert alert-danger">Internal Server error</div>`
    }

    if(pathname==='/')
    items=items.filter(element=>element!=='project_files');
        
    

    items.forEach(item => {
        const link = path.join(pathname, item);
        const itemFullStaticPath = path.join(fullStaticPath, item);

        let itemDetails = {};
        // let stats;
        // let icon;
        itemDetails.name = item;

        try {
            itemDetails.stats = fs.statSync(itemFullStaticPath);
        }
        catch (err) {
            mainContent = `<div class="alert alert-danger">Internal Server Error</div>`;
            return false;

        }



        if (itemDetails.stats.isDirectory()) {
            itemDetails.icon = '<ion-icon name="folder-open"></ion-icon>';
            [itemDetails.size, itemDetails.sizeBites] = calculateSizeD(itemFullStaticPath);
        }
        else {
            itemDetails.icon = '<ion-icon name="document"></ion-icon>';
            [itemDetails.size, itemDetails.sizeBites] =calculateSizeF(itemDetails.stats);
        }

        //last modeified
        itemDetails.timeStamp = parseInt(itemDetails.stats.mtimeMs);

        //convert time stamp to date
        itemDetails.date = new Date(itemDetails.timeStamp);
        itemDetails.date = itemDetails.date.toLocaleString();

        mainContent += `
        <tr data-name="${itemDetails.name}" data-size="${itemDetails.sizeBites}" data-time="${itemDetails.timeStamp}">
            <td>${itemDetails.icon} <a href="${link}" target='${itemDetails.stats.isFile() ? "_blank":""}'>${item}</a></td>
            <td>${itemDetails.size}</td>
            <td>${itemDetails.date}</td>
        </tr>`;
    });



    return mainContent;
};

module.exports = buildMainContent;
