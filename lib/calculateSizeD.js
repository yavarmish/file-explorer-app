const execSync  = require('child_process').execSync;


const calculateSizeD=itemFullStaticPath=>{
    const itemFullStaticPathCleaned=itemFullStaticPath.replace(/\s/g,'\ ');
    const commandOutput = execSync(`du -sh "${itemFullStaticPathCleaned}"`).toString();

    let fileSize = commandOutput.replace(/\s/g,'')
    fileSize=fileSize.split('/');

    fileSize=fileSize[0];
    const fileSizeUnit=fileSize.replace(/\d|\./g,'');
    const fileSizeNumer=parseFloat(fileSize.replace(/[a-z]/i,'')); 
    const units="BKMGT";

    const fileSizeBytes=fileSizeNumer*Math.pow(1024,units.indexOf(fileSizeUnit));


    return [fileSize,fileSizeBytes];
};

module.exports=calculateSizeD;


