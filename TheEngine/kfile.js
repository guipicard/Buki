const path = require('path');
const fs = require('fs');
let project = new Project('TheEngine');


project.addProvider = function(proj, isRoot=false){
    const sdl2 = true;//process.argv.indexOf("--sdl2") >= 0;
    if(sdl2){
        fs.copyFileSync("./sdl/lib/SDL2.dll", "./Deployment/SDL2.dll")
        fs.copyFileSync("./sdl/lib/SDL2_image.dll", "./Deployment/SDL2_image.dll")
        if(!isRoot){
            proj.addDefine("USE_SDL");
            proj.addIncludeDir(path.resolve("./sdl/include"));
            // proj.addIncludeDir(path.resolve("./TheEngine/sdl2_image/include"));
        }
        proj.addLib("./sdl/lib/SDL2")
        proj.addLib("./sdl/lib/SDL2main")
        proj.addLib("./sdl/lib/SDL2_image")
    }
};
project.kore = false;


project.addDefine("KINC_STATIC_COMPILE");
project.isStaticLib = true;

project.addIncludeDir(path.resolve("./TheEngine/includes"));
project.addFiles('src/**','includes/**');

project.addProvider(project,false);

resolve(project);