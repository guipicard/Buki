let project = new Project("Adventure of Lolo")

project.kore = false

project.addFile("AOL/**")

project.setDebugDir("Deployment")

project.addIncludeDir("./TheEngine/includes");
project.addIncludeDir("./AOL/includes");

project.flatten()

const otherproj = await project.addProject("TheEngine")

otherproj.addProvider(project, true)

resolve(project)