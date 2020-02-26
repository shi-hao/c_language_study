# 密码学    

<pre>
          |-对称算法-|-序列密码(stream)
          |          |-分组密码(block)
	      |          |-加密模式(ECB,CBC,GCM)
	      |          |-AES/DES/SM4
加密算法--|
		  |-非对称算法-|-公钥/私钥
		  |            |-数字签名(私钥加密公钥解密)
	      |            |-密钥交换(公钥加密私钥解密)
	      |            |-RSA/ECC/SM2
	      |
		  |-散列函数|-SHA1/MD1/SM4
</pre>
  
## 对称密码算法  
对称算法：加密密钥和解密密钥是相同的。    
对称密码可以分为两大类，序列密码和分组密码。    
序列密码：每次加密数据时，序列密码生成器生成和数据比特数一致的密码流，    
		  将数据和密码异或，得到密文。输入任意长度的数据，输出等长度的    
		  的密文。    
    
分组密码：每次加密一整块数据，每块的数据的长度必须是固定的，当明文数据    
		  长度不足时，需要将数据增补到一块的大小。    
    
<加密模式>  
分组密码有很多加密模式，比如ECB，CBC，CFB，GCM等，此处只介绍ECB，CBC。    
ECB（electronic codebook）:电码本模式，ECB模式简单，但是有一个致命问题，    
当明文输入相同时，输出也是相同，攻击者可以利用这个特点来猜测明文。    
如果两次发送了相同明文，拦截信息者会知道两次信息是相同的;    
攻击者可以提交明文给发送者，根据输出来猜测发送的密文数据;    
ECB模式问题很大，不建议使用。    
    
CBC（cipher block chaining）：加密块链接，CBC模式在加密时引入了初始向量    
（initialization vector， IV），即使输入相同，IV使输出也是不同的。    
基本原理是，生成一个与块大小相同的随机数IV，将明文和IV异或，然后再进行加密。    
然后第二块密文使用前一块密文作为IV，依次类推。    
  
sm4     
aes des    
    
  
## 非对称算法    
非对称算法：加密密钥和解密密钥不同，即分公钥和私钥，非对称算法又称为公钥算法。    
非对称算法主要用于数字签名和密钥交换，一般不用于实时数据的传输加密。  
  
rsa    
sm2     
    
<散列函数>    
散列函数，又称哈希函数，将任意长度的输入转换为定长输出的算法。  
哈希算法主要用来验证数据是否被更改。  

sha1    
md1    
sm3    
    
<数字签名>  
签名算法基本原理：  
需要被签名数据A  
使用哈希算法对A进行计算产生摘要信息B  
使用非对称算法私钥对B数据加密操作，输出数据C  
将A+C同时发出去  
  
接收到A+C后  
使用哈希算法对A进行计算产生摘要信息B'  
使用非对称算法公钥解密数据C，得到数据B"  
比较B'和B"是否相等  
相等则说明签名有效  