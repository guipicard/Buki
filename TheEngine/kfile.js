const path = require('path');
const fs = require('fs');
let project = new Project('TheEngine');


project.addProvider = function(proj, isRoot=false){
    proj.addLib("C:/Program Files (x86)/Visual Leak Detector/lib/Win64/vld")
    proj.addIncludeDir("C:/Program Files (x86)/Visual Leak Detector/include")
    const sdl2 = true;//process.argv.indexOf("--sdl2") >= 0;
    if(sdl2){
        fs.copyFileSync("./sdl/lib/SDL2.dll", "./Deployment/SDL2.dll")
        fs.copyFileSync("./sdl/lib/SDL2_image.dll", "./Deployment/SDL2_image.dll")
        fs.copyFileSync("./sdl/lib/SDL2_ttf.dll", "./Deployment/SDL2_ttf.dll")
        if(!isRoot){
            proj.addDefine("USE_SDL")
            proj.addIncludeDir(path.resolve("./sdl/include"))
            // proj.addIncludeDir(path.resolve("./TheEngine/sdl2_image/include"))
            // proj.addIncludeDir(path.resolve("./TheEngine/SDL2_ttf/include"))
            // proj.addIncludeDir('$(ProgramFiles)/Visual Leak Detector/include')
        }
        proj.addLib("./sdl/lib/SDL2")
        proj.addLib("./sdl/lib/SDL2main")
        proj.addLib("./sdl/lib/SDL2_image")
        proj.addLib("./sdl/lib/SDL2_ttf")
        // proj.addLib('$(ProgramFiles)/Visual Leak Detector/lib/Win64/vld')
        // proj.addLib('C:/Program Files/Visual Leak Detector/lib/Win64/vld_x64')
    }
};
project.kore = false;


project.addDefine("KINC_STATIC_COMPILE");
project.isStaticLib = true;

project.addIncludeDir(path.resolve("./TheEngine/includes"));
project.addFiles('src/**','includes/**');

project.addProvider(project,false);

resolve(project);