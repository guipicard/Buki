let project = new Project("Adventure of Lolo")

project.kore = false

project.addFile("AOL/**")

project.setDebugDir("Deployment")

project.addIncludeDir("./TheEngine/includes");
project.addIncludeDir("./AOL/includes");
project.addIncludeDir("./AOL/includes/Behaviours");
project.addIncludeDir("./AOL/includes/Prototypes");
project.addIncludeDir("./AOL/includes/Scenes");
project.addIncludeDir("./AOL/includes/snakey");

project.flatten()

const otherproj = await project.addProject("TheEngine")

otherproj.addProvider(project, true)

resolve(project)