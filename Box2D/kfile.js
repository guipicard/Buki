const path = require('path');
const fs = require('fs');

let project = new Project('Box2D');

project.kore = false;
project.addDefine("KINC_STATIC_COMPILE");
// project.setCmd()
project.isStaticLib = true;

project.addFiles('src/**');
project.addFiles('include/**');

project.addIncludeDir('./Box2D/include')

project.setCStd('c17')
project.cmdArgs.push("/experimental:c11atomics")

resolve(project);
