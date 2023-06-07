# Website Deployment

## Heroku

We use [Heroku](https://dashboard.heroku.com/apps) to deploy our website, so the coaches of Team-NL can use our website whenever they want.

## Pipeline

We wanted to automate the deployment of the website. This means that we do not want to manually deploy the website everytime we push stuff to the website through git. So we automated this process using the pipeline in gitlab. We made this pipeline using [this guide](https://gitlab.fdmci.hva.nl/se-ewa/deployment-workshop/-/blob/master/doc/general/gitlab-cicd/README.md). While doing so we encountered some problems. First we personalised it to link to our own repository. Which made the file look like this.

```yml
stages:
  - deploy

deploy_be:
    stage: deploy
    image: node:latest
    tags:
        - hva
    only:
        refs:
            - heroku-deployment
        changes:
          - "bmx-app-backend/**/*"  
    script:
        - git remote rm heroku-be-app || true
        - git remote add heroku-be-app https://heroku:$HEROKU_API_KEY@git.heroku.com/bmx-nl-app-be-staging.git || true
        - git subtree split --prefix bmx-app-backend -b splitting-staging-be
        - git push --force heroku-be-app splitting-staging-be:master
        - git branch -D splitting-staging-be

deploy_fe:    
    stage: deploy
    image: node:latest
    tags:
        - hva
    only:
        refs:
            - heroku-deployment
        changes:
          - "bmx-app/**/*"  
    script:
        - git remote rm heroku-fe-app || true
        - git remote add heroku-fe-app https://heroku:$HEROKU_API_KEY@git.heroku.com/bmx-nl-app-staging.git || true
        - git subtree split --prefix bmx-app -b splitting-staging-fe
        - git push --force heroku-fe-app splitting-staging-fe:master
        - git branch -D splitting-staging-fe
```

However, the pipeline still failed, giving us the following error: 'Your account has reached its concurrent builds limit.' This meant that we had too many builds running on our heroku webdeployment. So we had 'restart all dynos' on heroku, after that the front-end fully worked. However the back-end was still a problem, giving us this error: 'Branch 'splitting-staging-be' is not an ancestor of commit '5065e2353eaa04260c8f34a178ee9138fd402d6b'.' The front-end gave us the same problem a couple of commits later. We still haven't found a way to solve this issue.

## Common Issues

These were issues/errors that occurred when working on the pipeline/deploying to heroku

### Branch 'splitting-staging-X' is not an ancestor of commit 'X'

This is an issue that occurs when you don't have you remote branch set correctly, the error above basically means can't find commit in branch X to trace back to.

Fix: make sure to double-check whether you initialized a remote for your heroku app, either in your git interface or in the terminal of the IDE your currently using.

If this isn't the case make sure to run this command on your terminal: heroku git:remote -a [project-name-heroku] -r heroku-be-app

And run this command to see if it created a remote: git remote -v

### Failed to execute goal org.apache.maven.plugins:maven-compiler-plugin:3.8.1:compile (default-compile) on project bmx-app-backend:Fatal error compiling: invalid target release: 11 -> [Help 1]

This is an error you get when you didn't set your SDK properly in your IDE

Fix: make sure to check whether you have the correct SDK set in your IDE and in your pom.xml

### SQL Error 0, SQLState 08S01 Communications link failure

This error occurs when the communication line between the driver and the datasource to which the driver was connected failed before it was completely processed

The 2 reasons why the error occurred are the following:
- Network errors
- Database corruption

Luckily there is quite some information to find regarding this error and how to solve it.

I will link the following thread were more can be read on the issue [here](https://stackoverflow.com/questions/6865538/solving-a-communications-link-failure-with-jdbc-and-mysql), where we tried most of the solution given there.

After some concluding and thinking, there was also the realisation that this error might have occurred due to limitation of the oege database.
Since some settings can't be accessed without admin rights needed to for example changes variables like wait_timeout.


