# Minishell
Bu proje, 42 Okulları müfredatının bir parçası olarak C dilinde basit bir Unix kabuğu (shell) oluşturmayı amaçlamaktadır. `bash` veya `zsh` gibi kabukların temel işlevlerini yeniden uygulamayı hedefler.

## Proje Hakkında

Minishell, kullanıcıdan komutları okuyan, bu komutları ayrıştıran (parse eden) ve çalıştıran bir programdır. Temel amacı, bir komut satırı yorumlayıcısının nasıl çalıştığını anlamak ve sistem çağrıları, süreç (process) yönetimi ve dosya tanımlayıcıları (file descriptors) gibi temel Unix konseptlerini uygulamaktır.

## Temel Özellikler

Bu Minishell uygulaması aşağıdaki temel işlevleri desteklemektedir:

* **Komut Yorumlama**: Kullanıcıdan gelen girdiyi okur, ayrıştırır ve çalıştırır.
* **Komut Yolu**: `PATH` ortam değişkenini kullanarak çalıştırılabilir dosyaları bulur.
* **Dahili Komutlar (Built-ins)**:
    * `echo` ( `-n` seçeneği ile)
    * `cd` (sadece göreceli veya mutlak yol ile)
    * `pwd`
    * `export`
    * `unset`
    * `env` (seçeneksiz ve argümansız)
    * `exit`
* **Yönlendirmeler (Redirections)**:
    * `<` (Girdi yönlendirmesi)
    * `>` (Çıktı yönlendirmesi)
    * `<<` (Here Document)
    * `>>` (Çıktı ekleme)
* **Boru Hatları (Pipes)**: `|` karakteri ile birden fazla komutun çıktısını birbirine bağlama.
* **Ortam Değişkenleri**: `$DEGİSKEN` veya `${DEGİSKEN}` formatındaki ortam değişkenlerini komut çalıştırılmadan önce genişletme.
* **Sinyal Yönetimi**:
    * `Ctrl-C`: Çalışan bir süreci durdurmadan yeni bir komut satırı (prompt) gösterir.
    * `Ctrl-D`: Kabuğu sonlandırır (EOF).
    * `Ctrl-\`: Hiçbir şey yapmaz.
  
## Kurulum ve Derleme

1.  Projeyi klonlayın:
    ```bash
    git clone https://github.com/Muhammed4101/Minishell.git
    cd minishell
    ```

2.  Projeyi derlemek için `make` komutunu çalıştırın:
    ```bash
    make
    ```

## Kullanım

Derleme sonrası oluşan `minishell` dosyasını çalıştırın:

```bash
./minishell
```

Artık komutlarınızı girerek Minishell'i test edebilirsiniz.

## Yazar

* **Muhammed Arslan - Azizcan Tam** - (Muhammed4101 - Azizcan1212)

---
