## Git User

- **Set User and Email**

  ```bash
  git config --global user.name "yourUserName"
  git config --global user.email "yourEmail@whatever.com"
  ```

- **Cache the next git user and password (in-memory)**
  ```bash
  git config --global credential.helper cache --timeout=<seconds>
  ```
 
- **Cache the next git user and password (disk)**
  ```bash
  git config --global credential.helper store
  ```

- **Unset user and password cache credentials**
  ```bash
  git config --global --unset credential.helper
  ```

## Git Variables

- **Unset global config variables**
  ```bash
  git config --global --unset user.name
  git config --global --unset user.email
  ```

- **Display Global Configs Variables**
  ```bash
  git config -l
  ```
  
- **Edit Git Global Config Variables**
  ```bash
  git config --global --edit
  ```

## Branches

- **Display status of current branch**
  ```bash
  git status
  ```

- **Display local branch**
  ```bash
  git branch
  ```

- **Display all branch even on remote repository**
  ```bash
  git branch -a
  ```

- **Switch to a branch**
  ```bash
  git checkout NewBranchName
  ```

- **Create a new branch using the current branch you're currently in**
  ```bash
  git checkout -b NewBranchName
  ```
  
- **Create a new branch from a commit**
  ```bash
  git log
  git branch <branch name> <identifier>
  ```

- **Create a new EMPTY branch**

```bash
git switch --orphan <new branch>
git commit --allow-empty -m "New empty branch"
git push -u origin <new branch>
```
  
- **Download a branch from a remote**
  ```bash
  git checkout -t <remote-name>/<branch-name>
  ```
  
- **Stash some specific file changes from another branch**
  ```bash
  git checkout <main-branch>
  git checkout <another-branch> -- <file>
  ```
  
- **Delete branch locally**
  ```bash
  git branch -d <branch_name>
  git branch -D <branch_name>
  ```
  - The `-d` option is an alias for `--delete`, which only deletes the branch if it has already been fully merged in its upstream branch.
  - The `-D` option is an alias for `--delete --force`, which deletes the branch "irrespective of its merged status." [Source: man git-branch]

## Pulls

- **Remote changes are applied**
  ```bash
  git pull
  ```

- **Local changes are reapplied on top of the remote changes.**
  ```bash
  git pull --rebase
  ```
  
## Commits

- **Commit changes**

  use when writing a more detailed commit message
  ```bash
  git commit
  ```
  
- **Commit changes directly**

  use for simple commits that only requires a commit message, and no further information
  ```bash
  git commit -m <the-commit-message>
  ```
  
- **Go back to a certain commit (for specific files)**

  ```bash
  git checkout <commit-hash> -- file1/to/restore file2/to/restore
  ```

- **Go back to a certain commit**

  this will make the `commit hash` as the current head, and remove anything above it
  ```bash
  git reset --hard <commit-hash>
  ```

  After resetting to a certain commit, you might want to force push it to a repo if that repo also contains all the commits ahead in your local repo.
  ```bash
  git push --force
  ```
  
- **Edit a recent commit's message (locally)**
  ```bash
  git commit --amend
  ```
  
- **Edit a recent commit's message (pushed in a repo)**
  ```bash
  git commit --amend
  git push --force-with-lease <remote-name> <branch-name>
  // <remote-name> and <branch-name> are optional
  ```

- **Edit a history of future commits from a root commit**
  
  This will prompt an interactive shell where you can edit
  future commits after the chosen starting root
  `<commit-hash>` until to the current `HEAD` commit. 
  ```bash
  git rebase -i <commit-hash>
  ```

  After entering the command above it will revert your files
  to the state of the commit above the given `<commit-hash>`.

  Then you can apply the changes to the files during that 
  commit, then add those changes using:

  ```bash
  git add .
  ```

  After editing the changes in that commit you can continue the rebase step with:

  ```bash
  git rebase --continue
  ```

  If there are conflicts after continue, fix it then repeat 
  the `git add .` and `git rebase --continue` until you reach
  the `HEAD` commit. 

  **Note:** the given `<commit-hash>` is not included when 
  editing.

## Stages

- **Stage (add) the new edited files**
  ```bash
  git add <files>...
  ```

- **Unstage (remove) the added files when the git `add` command was used**
  ```bash
  git restore --staged <file>...
  ```
  
- **Show staged file changes**
  ```bash
  git diff --cached
  ```

## Remote

- **Show remote repository**
  ```bash
  git remote
  git remote -v
  ```

- **Add a remote repository**
  ```bash
  git remote add <name> <url>
  ```

- **Remove a remote repository**
  ```bash
  git remote remove <name>
  ```

# Submodules

**add a submodule in a repo**
```bash
git submodule add <url>
```

**after cloning a repo with submodules**

```bash
git submodule update --init --recursive
```

**updating a repo with the latest changes to submodules**

```bash
git submodule update --recursive --remote
```

# Dot Character
use to denote `<all files>` instead of just selecting a specific file name.

Example, to add all changes:

```bash
git add .
```

# Merge Vs Rebase

- (`feature` -> `main`) merge is mostly used for bringing new commits from feature branch to master/main branch
- (`main` -> `feature`) rebase is mostly used for bringing new commits from master/main branch to a feature branch

- **Merge branch**

  _This operation stacks the incoming feature branch commits on top of the existing commit history of the main branch._

  ```bash
  git checkout <main-branch>
  git merge <feature-branch>
  ```

- **Rebase branch**

  _This operation temporarily removes the current feature branch commits, stacks the new incoming commits from the main branch on top of the feature branch history, and then restacks the current feature branch commits back._

  ```bash
  git checkout <feature-branch>
  git rebase <main-branch>
  ```

# Tags

**List all of the tags**

```bash
git tag -l
```

**Delete a local Git tag**

```bash
git tag -d <tagname>
```

**Create a local Git tag**

```bash
git tag <tagname>
```

**Create a local annotated tag**

```bash
git tag <tagname> -a
```

**Push all local tag**

```bash
git push origin --tags
```

**Push a specific local tag**

```bash
git push origin <tag>
```

**Checkout a tag**

```bash
git checkout tags/<tag_name>
```
