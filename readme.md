+ 1、进入项目地址，通过命令git init将项目初始化成git本地仓库

  ```
  git init
  ```

+ 2、将项目内所有文件都添加到暂存区

  ```
  git add .
  ```

+ 3、该命令会将git add .存入暂存区修改内容提交至本地仓库中，若文件未添加至暂存区，则提交时不会提交任何修改。

  ```
  git commit -m 'xxx'   //xxx是备注名
  ```

+ 4、在github上新建一个仓库，复制仓库地址，然后使用命令将本地仓库与远程仓库建立连接
  （4.1）`git remote add origin  xxx`       //xxx是git仓库的地址
  （4.2）4.1这个步骤可能出现错误 提示fatal: remote origin already exists
  执行：`git remote rm origin`命令
  （4.3）再执行（4.1）的命令

+ 5、把暂存区的代码推到远程仓库

  ```git push -u origin master
  git push -u origin master

+ 6.查看仓库更改记录

  ``` git state
  git status

+ 7

