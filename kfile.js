let project = new Project("BukiEngine")

project.kore = false

project.addFile("Game/**")

project.setDebugDir("Deployment")

project.addIncludeDir("./vendor/Box2D/include/box2d");
project.addIncludeDir("./Engine/includes");
project.addIncludeDir("./Game/includes");

project.flatten()

const engineproj = await project.addProject("Engine")
engineproj.addProvider(project, true)

const boxproj = await project.addProject("Box2D")
engineproj.addProvider(boxproj, true)

resolve(project)