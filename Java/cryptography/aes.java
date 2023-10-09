import java.util.*;
import java.security.InvalidAlgorithmParameterException;
import java.security.InvalidKeyException;
import java.security.NoSuchAlgorithmException;
import java.security.SecureRandom;
import java.security.spec.InvalidKeySpecException;
import java.security.spec.KeySpec;

import javax.crypto.BadPaddingException;
import javax.crypto.Cipher;
import javax.crypto.IllegalBlockSizeException;
import javax.crypto.KeyGenerator;
import javax.crypto.NoSuchPaddingException;
import javax.crypto.SecretKey;
import javax.crypto.SecretKeyFactory;
import javax.crypto.spec.IvParameterSpec;
import javax.crypto.spec.PBEKeySpec;
import javax.crypto.spec.SecretKeySpec;

public class AES
{
    public static void main(String[] Args)
    {
        try{
            String plainText = "this is a sensitive message";

            SecretKey AES128KEY = AES.generateKey("RandomPasswordString", "RandomSaltString");
            IvParameterSpec randomIV = AES.generateIV();
            String algorithm = "AES/CBC/PKCS5Padding";

            String cipherText = AES.encrypt(algorithm, plainText, AES128KEY, randomIV);
            String recoverText = AES.decrypt(algorithm, cipherText, AES128KEY, randomIV);

            System.out.println("plainText   : "+plainText+"\nlength = "+plainText.length()+"\n");
            System.out.println("cipherText  : "+cipherText+"\nlength = "+cipherText.length()+"\n");
            System.out.println("recoverText : "+recoverText+"\nlength = "+recoverText.length()+"\n");

            if(!recoverText.equals(plainText))
            {
                throw new AssertionError("AES ENCRYPTION-DECRYPTION : FAILED");
            }
            else
            {
                System.out.println("AES ENCRYPTION-DECRYPTION : PASSED");
            }
        } catch (Exception err)
        {
            err.printStackTrace();
        }
    }

    public static String keyToString(SecretKey key)
    {
        return Base64.getEncoder().encodeToString(key.getEncoded());
    }

    public static SecretKey generateKey(int n) throws NoSuchAlgorithmException
    {
        KeyGenerator KEYRNG = KeyGenerator.getInstance("AES");
        KEYRNG.init(n);
        return KEYRNG.generateKey();
    }

    public static SecretKey generateKey(String password, String salt)
        throws
        InvalidKeySpecException,
            NoSuchAlgorithmException
    {
        KeySpec PSWRDKEY = new PBEKeySpec(password.toCharArray(), salt.getBytes(), 65536, 128);
        SecretKeyFactory KEYGENSCHEME = SecretKeyFactory.getInstance("PBKDF2WithHmacSHA256");
        return new SecretKeySpec(KEYGENSCHEME.generateSecret(PSWRDKEY).getEncoded(), "AES");
    }

    public static IvParameterSpec generateIV()
    {
        byte[] IV = new byte[16];
        new SecureRandom().nextBytes(IV);
        return new IvParameterSpec(IV);
    }

    public static String encrypt(String encryptionScheme, String plainText, SecretKey key, IvParameterSpec IV)
        throws
            NoSuchAlgorithmException,
            InvalidAlgorithmParameterException,
            InvalidKeyException,
            NoSuchPaddingException,
            BadPaddingException,
            IllegalBlockSizeException
    {
        Cipher AESENCRYPT = Cipher.getInstance(encryptionScheme);
        AESENCRYPT.init(Cipher.ENCRYPT_MODE, key, IV);
        byte[] cipherText = AESENCRYPT.doFinal(plainText.getBytes());
        return Base64.getEncoder().encodeToString(cipherText);
    }

    public static String decrypt(String decryptionScheme, String cipherText, SecretKey key, IvParameterSpec IV)
        throws
            NoSuchAlgorithmException,
            InvalidAlgorithmParameterException,
            InvalidKeyException,
            NoSuchPaddingException,
            BadPaddingException,
            IllegalBlockSizeException
    {
        Cipher AESDECRYPT = Cipher.getInstance(decryptionScheme);
        AESDECRYPT.init(Cipher.DECRYPT_MODE, key, IV);
        byte[] recoveredText = AESDECRYPT.doFinal(Base64.getDecoder().decode(cipherText));
        return new String(recoveredText);
    }
}
