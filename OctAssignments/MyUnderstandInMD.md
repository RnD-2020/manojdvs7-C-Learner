# **Git**
Git is a distributed version-control system for tracking changes in source code during software development.

## **First Time Git Setup** 
When you install **Git** in your system, there are things to customize in Git when you run **for first time.**<br/> 
### **1.Identity**
When you install **Git** in your system, there are things to customize in Git when you run **for first time.**<br/>
```git
    $ git config --global user.name "YourUserName"
    $ git config --global user.email YourEmailaddress
```
### **2.Setting Editor**
This will set your default text editor.This can be done by using the following commad:<br/>
```git
    $ git config --global core.editor editorname
```
### **3.Checking the Git Settings**
This will help you to view all the Settings of Git in your system.You can verify them and make changes if any.This can be done using this commad:<br/>
```git
    $ git config --list
```
## **Git Basics**
This will cover all the basic commands and functionalities in Git<br/>
### **1.Initializing the Git Repository**
This creates a new subdirectory named .git that contains all of your necessary repository files basically Git repository skeleton.</b>This can be done using the following commad:<br/>
```git
    $ git init
```
This commad to be exectuted in your project directory.

 ### **2.Cloning Repository**
If you want to get a copy of an **existing** Git repository — for example, a project you’d like to contribute.This can be done using the following commad:<br/>
```git
    $ git clone url.git
```
### **3.Adding remote Repository**
This will help you to add remote repository.This can be done using the following commad:<br/>
```git
   $ git remote add origin url.git
```
### **4.Tracking New Files**
 Add files to be tracked. The changes made in the added files are tracked. This can be done using the following commad:<br/>
```git
   $ git add filename
```
### **5.Removing the file**
 You can also remove a file from tracking. This can be done using the following commad:<br/>
```git
   $ git rm filename
```
### **6.Commiting the changes**
 You can save your changes made in added files step by step using commits. This can be done using the following commad:<br/>
```git
    $ git commit -m "name of commit"
```
You can view your commit history using the following commad:<br/>
```git
    $ git log
```
 You can also retrive the changes by switching from one commit to another commit.<br/>
 ### **7.Pushing to remote repository**
 This will push the added files to remote repository,by default to master branch. This can be done using the following commad:<br/>
```git
   $ git push -u origin master
```
All the changes are to be pushed to remote repository.