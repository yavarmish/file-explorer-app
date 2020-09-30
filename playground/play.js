const {execSync}=require('child_process').execSync;

try{
    console.log(child_process.execSync('du -sh "/mnt/c/Users/Sanjula/Desktop/web\ d\ projects/9.File\ explorer\ app"').toString());
}
catch(err)  
{
    console.log(`${err}`);
}

