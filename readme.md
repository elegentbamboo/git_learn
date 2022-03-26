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

**B，Github常用的命令：**

- ```
  git branch
  ```

   查看本地所有分支

- ```
  git status
  ```

   查看当前状态

- ```
  git commit
  ```

   提交

- ```
  git branch -a
  ```

   查看所有的分支

- ```
  git branch -r 
  ```

  查看远程所有分支

- ```
  git commit -am "init"
  ```

   提交并且加注释

- git remote add origin git@192.168.1.119:ndshowgit

- ```
  push origin master
  ```

   将文件给推到服务器上

- ```
  git remote show origin
  ```

   显示远程库origin里的资源

- `git push origin master:develop`

- `git push origin master:hb-dev` 将本地库与服务器上的库进行关联

- `git checkout --track origin/dev` 切换到远程dev分支

- `git branch -D master develop` 删除本地库develop

- `git checkout -b dev` 建立一个新的本地分支dev

- `git merge origin/dev` 将分支dev与当前分支进行合并

- `git checkout dev` 切换到本地dev分支

- `git remote show` 查看远程库

- `git add .git rm` 文件名(包括路径) 从git中删除指定文件* git clone git://github.com/schacon/grit.git 从服务器上将代码给拉下来

- `git config --list` 看所有用户

- `git ls-files` 看已经被提交的

- `git rm [file name]` 删除一个文件

- git commit -a 提交当前repos的所有的改变

- git add [file name] 添加一个文件到

- git indexgit commit -v 当你用－v参数的时候可以看commit的差异

- git commit -m "This is the message describing the commit" 添加commit信息

- git commit -a -a是代表add，把所有的change加到git index里然后再commit

- git commit -a -v 一般提交命令

- git log 看你commit的日志

- git diff 查看尚未暂存的更新

- git rm a.a 移除文件(从暂存区和工作区中删除)

- git rm --cached a.a 移除文件(只从暂存区中删除)

- git commit -m "remove" 移除文件(从Git中删除)

- git rm -f a.a 强行移除修改后文件(从暂存区和工作区中删除)

- git diff --cached 或 $ git diff --staged 查看尚未提交的更新

- git stash push 将文件给push到一个临时空间中

- git stash pop 将文件从临时空间pop下来

git remote add origin git@github.com:username/Hello-World.git

git push origin master 将本地项目给提交到服务器中

git pull 本地与服务器端同步

git push (远程仓库名) (分支名) 将本地分支推送到服务器上去。

git push origin serverfix:awesomebranch

git fetch 相当于是从远程获取最新版本到本地，不会自动merge

git commit -a -m "log_message" (-a是提交所有改动，-m是加入log信息) 本地修改同步至服务器端 ：

git branch branch_0.1 master 从主分支master创建branch_0.1分支

git branch -m branch_0.1 branch_1.0 将branch_0.1重命名为branch_1.0

git checkout branch_1.0/master 切换到branch_1.0/master分支du -hs

git branch 删除远程branchgit push origin :branch_remote_namegit branch -r -d branch_remote_name

 

 **C，删除远程仓库（比如GitHub）的目录或文件**

具体操作

1. 拉取远程的Repo到本地（如果已经在本地，可以略过） 
2. $ git clone xxxxxx
3. 在本地仓库删除文件 
4. $ git rm 我的文件
5. 在本地仓库删除文件夹 
6. $ git rm -r 我的文件夹/
   此处-r表示递归所有子目录，如果你要删除的，是空的文件夹，此处可以不用带上-r。
7. 提交代码 
8. $ git commit -m"我的修改"
9. 推送到远程仓库（比如GitHub） 
10. $ git push origin xxxxxx

补充**: git rm**

查看git rm的说明文档:

$ git rm -h

用法：git rm [<选项>] [--] <文件>...

  -n, --dry-run  

