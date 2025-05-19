const path = require('path');
const fs = require('fs');

let engineProject = new Project('Engine');


engineProject.addProvider = function(proj, isRoot=false){
    proj.addLib("./vendor/Visual Leak Detector/lib/Win64/vld")
    proj.addIncludeDir("./vendor/Visual Leak Detector/include")
    engineProject.addIncludeDir("./Box2D/include/box2d")
    const sdl2 = true;//process.argv.indexOf("--sdl2") >= 0;
    if(sdl2){
        fs.copyFileSync("./vendor/SDL2/lib/SDL2.dll", "./Deployment/SDL2.dll")
        fs.copyFileSync("./vendor/SDL2/lib/SDL2_image.dll", "./Deployment/SDL2_image.dll")
        fs.copyFileSync("./vendor/SDL2/lib/SDL2_ttf.dll", "./Deployment/SDL2_ttf.dll")
        fs.copyFileSync("./vendor/SDL2/lib/SDL2_mixer.dll", "./Deployment/SDL2_mixer.dll")
        if(!isRoot){
            proj.addDefine("USE_SDL")
            proj.addIncludeDir("./vendor/SDL2/include")
        }
        proj.addLib("./vendor/SDL2/lib/SDL2")
        proj.addLib("./vendor/SDL2/lib/SDL2main")
        proj.addLib("./vendor/SDL2/lib/SDL2_image")
        proj.addLib("./vendor/SDL2/lib/SDL2_ttf")
        proj.addLib("./vendor/SDL2/lib/SDL2_mixer")
    }
};

engineProject.kore = false;
engineProject.addDefine("KINC_STATIC_COMPILE");
engineProject.isStaticLib = true;

engineProject.addIncludeDir("./Engine/includes")
// engineProject.addIncludeDir("./Box2D/include")
engineProject.addFiles('src/**','includes/**');

engineProject.addProvider(engineProject, false)

console.log("engine")
resolve(engineProject);
