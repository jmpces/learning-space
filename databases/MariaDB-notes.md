# Install Database

## Install MariaDB in Ubuntu Linux

```sql
sudo apt-get update
sudo apt-get upgrade
sudo apt-get install software-properties-common
sudo apt-get install mariadb-server mariadb-client
```

## Install MariaDB in Arch Linux

```sql
sudo pacman -Syu
sudo pacman -S mariadb
```

## Check if MariaDB is running

```sql
sudo systemctl status mariadb
```

## Run MariaDB if not running

```sql
sudo systemctl start mariadb
```

## Enable MariaDB to start system start-up

```sql
sudo systemctl enable mariadb
```

## Secure you MariaDB

```sql
sudo mysql_secure_installation
```

## Login to root user

- In **ubuntu** linux the password input by `sudo` is already the password use to access the root user.
- But if you don't want to `sudo` open the root user, you can set a password for the **root user** in one of the steps in `sudo mysql_secure_installation`
- In **windows** the root password is the one you set during installation, make sure to remember that.

```sql
sudo mariadb -u root -p
```

## Create a new admin user then, grant all privileges to it

```sql
CREATE USER 'admin_user'@'localhost' IDENTIFIED BY 'secret_password';
GRANT ALL PRIVILEGES ON *.* TO 'admin_user'@'localhost';
FLUSH PRIVILEGES;
```

## Login to admin_user

```sql
sudo mariadb -u admin_user -p
```

## Create A User For A Server

1. **Create A User Using Root User On The Server**
    ```sql
    CREATE USER <db_user_name>@localhost IDENTIFIED BY '<db_user_password>';
    GRANT ALL privileges ON `<database_name>`.* TO <db_user_name>@`<user_address>` IDENTIFIED BY '<db_user_password>';
    ```
    If you want to access only a table use **experimental.SpecificTableName**

    - The `<user_address>` could be the IP or URL address of a user or client.

2. **Remove The User If You Want/Need To**
    ```sql
    DROP USER IF EXISTS <db_user_name>@<user_address>;
    ```

3. **Access Database From Client**

    ```zhs
    mariadb -u <db_user_name> -p<db_user_password> -h <server_address> <database_name>
    ```

    - The `<server_address>` could be an IP or URL address where the database resides.
