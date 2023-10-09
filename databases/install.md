# **Install Database**

## **Install MariaDB in Ubuntu Linux**

```sql
sudo apt-get update
sudo apt-get upgrade
sudo apt-get install software-properties-common
sudo apt-get install mariadb-server mariadb-client
```

## **Check if MariaDB is running**

```sql
sudo systemctl status mariadb
```

## **Run MariaDB if not running**

```sql
sudo systemctl start mariadb
```

## **Enable MariaDB to start system start-up**

```sql
sudo systemctl enable mariadb
```

## **Secure you MariaDB**

```sql
sudo mysql_secure_installation
```

## **Login to root user**

- In **ubuntu** linux the password input by `sudo` is already the password use to access the root user.
- But if you don't want to `sudo` open the root user, you can set a password for the **root user** in one of the steps in `sudo mysql_secure_installation`
- In **windows** the root password is the one you set during installation, make sure to remember that.

```sql
sudo mariadb -u root -p
```

## **Create a new admin user then, grant all privileges to it**

```sql
CREATE USER 'admin_user'@'localhost' IDENTIFIED BY 'secret_password';
GRANT ALL PRIVILEGES ON *.* TO 'admin_user'@'localhost';
FLUSH PRIVILEGES;
```

## **Login to admin_user**

```sql
sudo mariadb -u admin_user -p
```

## **Create A User For A Server**

1. **Create a user using root user on the server**
    ```sql
    CREATE USER UserName@localhost IDENTIFIED BY 'UserPassword';
    GRANT ALL privileges ON `DatabaseName`.* TO UserName@`UserAddress` IDENTIFIED BY 'UserPassword';
    ```
    If you want to access only a table use **experimental.SpecificTableName**

2. **Remove the user if you want/need**
    ```sql
    DROP USER IF EXISTS UserName@UserAddress;
    ```

3. **access database using client**

    ```zhs
    mariadb -u UserName -pUserPassword -h ServerAddress DatabaseName
    ```
