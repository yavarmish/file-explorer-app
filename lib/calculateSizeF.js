const { isMainThread } = require("worker_threads");


const calculateSizeF=stats=>{
    const fileSizeBytes=stats.size;
    const units="BKMGT";

    const index=Math.floor(Math.log10(fileSizeBytes)/3);
    let fileSize=(fileSizeBytes/Math.pow(1024,index)).toFixed(1);
    const unit=units[index];
    fileSize=`${fileSize}${unit}`;
    


    return [fileSize,fileSizeBytes];
};

module.exports=calculateSizeF;


