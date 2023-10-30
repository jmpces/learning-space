# SSH login

```bash
ssh <user_name>@<address>
```

# [Generate SSH key using Git (click here)](https://git-scm.com/book/en/v2/Git-on-the-Server-Generating-Your-SSH-Public-Key)

SSH files should appear in your `~/.shh` for ubuntu systems.

# Premission `0664`

1. Go to your `.ssh` folder.

    ```bash
    cd /home/$USER/.ssh
    ```

2. Check the permission of the private key.

    ```bash
    ls -l id_rsa
    ```

    Output:

    ```bash
    -rw-rw-r-- 1 your_username your_username 1234 Oct 30 12:34 id_rsa
    ```

    The permissions `rw-rw-r--` in the above example are too open (664). To fix this, you should make the file readable and writable only by the owner and not accessible by others.

3. Change the permission to the private key

    ```bash
    chmod 600 id_rsa
    ```

    This command sets the file permissions to 600, which means it is readable and writable only by the owner.

4. Verify that the permissions have been updated correctly:

    ```bash
    ls -l id_rsa
    ```

    Output:

    ```bash
    -rw------- 1 your_username your_username 1234 Oct 30 12:34 id_rsa
    ```

    The permissions are now correct, and your private key is no longer accessible by others.