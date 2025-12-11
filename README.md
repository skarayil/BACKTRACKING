# 🔄 Backtracking Algorithms - Problem Solving with Recursive Exploration

<div align="center">

![42 School](https://img.shields.io/badge/School-42-black?style=for-the-badge&logo=42)
![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)
![Algorithms](https://img.shields.io/badge/Algorithms-Backtracking-blue?style=for-the-badge)
![Problems](https://img.shields.io/badge/Problems-7-success?style=for-the-badge)

**Backtracking algoritması ile problem çözme sanatını öğrenin**

*Bu repo, backtracking algoritmasının prensiplerini ve uygulamalarını çeşitli klasik problemler üzerinden öğretmek için tasarlanmıştır.*

[Backtracking Nedir?](#-backtracking-nedir) • [Problemler](#-problemler) • [Kurulum](#-kurulum) • [Öğrenme Yolu](#-öğrenme-yolu)

</div>

---

## 🎯 Projenin Amacı

<img align="right" alt="Algorithm Animation" width="300" src="https://media.giphy.com/media/v1.Y2lkPTc5MGI3NjExZmM0cG80aTJ4aDdrMXg5aml4bjhzcHJvdDNydHVpbHJkbXBrZzM4NyZlcD12MV9naWZzX3NlYXJjaCZjdD1n/zMukICnMEZmSf8zvXd/giphy.gif">

Bu repo, **backtracking algoritmasını** öğrenmek ve uygulamak için 7 farklı zorluk seviyesinde klasik  problemi içerir. Her problem, algoritmanın farklı yönlerini ve kullanım senaryolarını öğretmek üzere tasarlanmıştır.

### 🚀 **Ana Öğrenme Hedefleri:**

#### 🧠 **Backtracking Mantığını Kavrama**
- Çözüm uzayını sistematik olarak keşfetme
- Geçersiz yolları erkenden kesme (pruning)
- Çözüm bulunduğunda veya tüm uzay tarandığında durma

#### 🔄 **Recursive Düşünme Yeteneği**
- Problem durumlarını recursive olarak tanımlama
- Base case ve recursive case ayrımı yapma
- Call stack yönetimi ve state tracking

#### 🎯 **Kısıtlama Kontrolü (Constraint Checking)**
- Problem kısıtlamalarını doğru belirleme
- Kısıtlamaları efficient kontrol etme
- Early termination stratejileri geliştirme

#### 🏗️ **State Management**
- Problem durumunu (state) doğru modelleme
- State'i modify etme ve geri alma (backtrack)
- Memory efficient state representation

#### 📊 **Algoritma Analizi**
- Time complexity analizi (genelde exponential)
- Space complexity analizi (recursive stack)
- Optimization teknikleri (memoization, pruning)

---

## 📚 Backtracking Nedir?

<div align="center">

![Algorithm](https://img.shields.io/badge/Type-Recursive-blue?style=for-the-badge)
![Complexity](https://img.shields.io/badge/Complexity-Exponential-orange?style=for-the-badge)
![Strategy](https://img.shields.io/badge/Strategy-Depth--First-green?style=for-the-badge)

</div>

### 🔍 **Algoritma Prensibi**

**Backtracking**, bir çözüm uzayını sistematik olarak araştırarak tüm olası çözümleri bulan veya optimal çözümü arayan bir algoritmik tekniktir.

#### 📖 **Temel Mantık:**

```
1. Bir seçim yap (Make a choice)
2. Bu seçimin sonuçlarını keşfet (Explore)
3. Çözüm bulundu mu?
   ✅ Evet → Kaydet/Yazdır
   ❌ Hayır → Geri dön ve başka seçim dene (Backtrack)
```

### 🎨 **Algoritma Şablonu**

```c
void backtrack(state, choices) {
    // BASE CASE: Çözüm bulundu mu?
    if (is_solution(state)) {
        process_solution(state);
        return;
    }
    
    // RECURSIVE CASE: Tüm seçimleri dene
    for (each choice in choices) {
        // 1. CONSTRAINT CHECK: Seçim geçerli mi?
        if (is_valid(choice, state)) {
            
            // 2. MAKE CHOICE: Seçimi yap
            make_choice(choice, state);
            
            // 3. EXPLORE: Recursive olarak devam et
            backtrack(state, remaining_choices);
            
            // 4. BACKTRACK: Seçimi geri al
            undo_choice(choice, state);
        }
    }
}
```

### 🌳 **Decision Tree Visualization**

```
                    [Initial State]
                    /    |    \
                   /     |     \
              [Choice1] [Choice2] [Choice3]
                 /|\       |          |
                / | \      |          |
               /  |  \     |          |
          [C1.1][C1.2][C1.3]         ...
             /     |      \
            /      |       \
      [Solution] [Dead] [Continue]
                  End
```

---

## 🎮 Problemler

### 1️⃣ **Flood Fill** - Başlangıç Seviyesi

<div align="center">

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Concept](https://img.shields.io/badge/Concept-2D%20Traversal-blue?style=for-the-badge)

</div>

#### 📝 **Problem Tanımı**
2D bir haritada, belirli bir noktadan başlayarak, aynı değere sahip tüm bağlantılı alanları değiştirme problemi. Paint programlarındaki "Boya Kovası" aracı gibi çalışır.

#### 🎯 **Öğretilen Konseptler**
- **2D Array Traversal**: İki boyutlu dizilerde gezinme
- **Boundary Checking**: Harita sınırlarını kontrol etme
- **Recursive DFS**: Depth-first search ile alan tarama
- **Base Case Recognition**: Ne zaman durulacağını belirleme

#### 🧩 **Backtracking Özellikleri**
```
State: Current position (x, y)
Choices: 4 directions (up, down, left, right)
Constraint: In bounds AND same character
Goal: Fill all connected cells
```

#### 💡 **Örnek**
```
Input (begin at 1,1):        Output:
11111                        11111
10001                        1FFF1
10101                        1F1F1
10001                        1FFF1
11111                        11111
```

#### 🔧 **Dosyalar**
- `floodfill/floodfill.c` - Implementation
- `floodfill/floodfill.txt` - Detailed explanation

---

### 2️⃣ **Permutations** - Başlangıç/Orta Seviye

<div align="center">

![Difficulty](https://img.shields.io/badge/Difficulty-Easy--Medium-yellow?style=for-the-badge)
![Concept](https://img.shields.io/badge/Concept-String%20Permutation-blue?style=for-the-badge)

</div>

#### 📝 **Problem Tanımı**
Verilen bir string'in tüm permütasyonlarını (tüm olası sıralamalarını) alfabetik sırada üretme problemi.

#### 🎯 **Öğretilen Konseptler**
- **Permutation Generation**: Tüm sıralamaları üretme
- **Used Array Technique**: Kullanılmış elemanları izleme
- **Lexicographic Order**: Alfabetik sıralama mantığı
- **String Building**: Dinamik string oluşturma

#### 🧩 **Backtracking Özellikleri**
```
State: Current string being built
Choices: All unused characters
Constraint: Character not used yet
Goal: Full-length permutation
```

#### 💡 **Örnek**
```bash
$> ./permutations abc
abc
acb
bac
bca
cab
cba
```

#### 🔧 **Dosyalar**
- `permutations/permutations.c` - Implementation
- `permutations/permutations.txt` - Detailed explanation

---

### 3️⃣ **Powerset (Subset Sum)** - Orta Seviye

<div align="center">

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Concept](https://img.shields.io/badge/Concept-Subset%20Generation-blue?style=for-the-badge)

</div>

#### 📝 **Problem Tanımı**
Bir sayı kümesinin, toplamı hedef sayıya eşit olan tüm alt kümelerini bulma problemi.

#### 🎯 **Öğretilen Konseptler**
- **Subset Generation**: Alt küme oluşturma
- **Sum Tracking**: Toplam izleme
- **Binary Choice Pattern**: Include/Exclude mantığı
- **Dynamic Solution Building**: Çözümü adım adım inşa etme

#### 🧩 **Backtracking Özellikleri**
```
State: Current subset + running sum
Choices: Include OR Exclude current element
Constraint: Sum doesn't exceed target
Goal: Sum equals target
```

#### 💡 **Örnek**
```bash
$> ./powerset 3 1 0 2 4 5 3
3
0 3
1 2
1 0 2
```

#### 🔧 **Dosyalar**
- `powerset/powerset.c` - Implementation
- `powerset/powerset.txt` - Detailed explanation

---

### 4️⃣ **N-Queens** - Orta/İleri Seviye

<div align="center">

![Difficulty](https://img.shields.io/badge/Difficulty-Medium--Hard-red?style=for-the-badge)
![Concept](https://img.shields.io/badge/Concept-Constraint%20Checking-blue?style=for-the-badge)

</div>

#### 📝 **Problem Tanımı**
NxN satranç tahtasına N adet veziri, hiçbiri birbirini tehdit etmeyecek şekilde yerleştirme problemi. Klasik AI problemidir.

#### 🎯 **Öğretilen Konseptler**
- **Complex Constraint Checking**: Çoklu kısıtlama kontrolü
- **Diagonal Check Logic**: Çapraz kontrol mantığı
- **Column-by-Column Strategy**: Sütun bazlı çözüm
- **Optimization Techniques**: Erken kesme (pruning)

#### 🧩 **Backtracking Özellikleri**
```
State: Queens placed so far (column by column)
Choices: Rows 0 to N-1 for current column
Constraints:
  - Not same row
  - Not same diagonal
Goal: All N queens placed safely
```

#### 💡 **Örnek**
```bash
$> ./n_queens 4
1 3 0 2
2 0 3 1

# Visualization of "1 3 0 2":
. Q . .    (row 0: queen at col 1)
. . . Q    (row 1: queen at col 3)
Q . . .    (row 2: queen at col 0)
. . Q .    (row 3: queen at col 2)
```

#### 🔧 **Dosyalar**
- `n_queens/n_queens.c` - Implementation
- `n_queens/n_queens.txt` - Detailed explanation

---

### 5️⃣ **RIP (Remove Invalid Parentheses)** - İleri Seviye

<div align="center">

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-darkred?style=for-the-badge)
![Concept](https://img.shields.io/badge/Concept-String%20Validation-blue?style=for-the-badge)

</div>

#### 📝 **Problem Tanımı**
Dengesiz parantez string'inden minimum sayıda parantez silerek, tüm dengeli versiyonları bulma problemi.

#### 🎯 **Öğretilen Konseptler**
- **String Validation**: String geçerliliği kontrolü
- **Minimum Removal Calculation**: Minimum silme sayısını bulma
- **Character Removal Strategy**: Karakter silme stratejisi
- **Duplicate Prevention**: Tekrarlayan çözümleri önleme

#### 🧩 **Backtracking Özellikleri**
```
State: Current string + removal count
Choices: Remove '(' OR Remove ')' at each position
Constraint: Total removals = calculated minimum
Goal: Balanced parentheses with min removals
```

#### 💡 **Örnek**
```bash
$> ./rip '( ( )'
_ ( )    # Remove first '('
( _ )    # Remove second '('

$> ./rip '( ) ( ) ) ( )'
( ) ( ) _ ( )
( ) ( _ ) ( )
( _ ( ) ) ( )
```

#### 🔧 **Dosyalar**
- `rip/rip.c` - Implementation
- `rip/rip.txt` - Detailed explanation

---

### 6️⃣ **TSP (Traveling Salesman Problem)** - İleri Seviye

<div align="center">

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-darkred?style=for-the-badge)
![Concept](https://img.shields.io/badge/Concept-Optimization-blue?style=for-the-badge)

</div>

#### 📝 **Problem Tanımı**
Verilen şehirler kümesinde, tüm şehirleri ziyaret edip başlangıç noktasına dönen en kısa yolu bulma problemi. NP-hard problemlerden biridir.

#### 🎯 **Öğretilen Konseptler**
- **Path Optimization**: Yol optimizasyonu
- **Distance Calculation**: Mesafe hesaplama (Euclidean)
- **Pruning Strategies**: Dallanma kesme stratejileri
- **Best Solution Tracking**: En iyi çözümü takip etme

#### 🧩 **Backtracking Özellikleri**
```
State: Cities visited + current path length
Choices: All unvisited cities
Constraint: Current path < best path (pruning)
Goal: All cities visited, minimum total distance
```

#### 💡 **Örnek**
```bash
$> cat square.txt
1, 1
0, 1
1, 0
0, 0

$> ./tsp < square.txt
4.00

# Forms a square path: (0,0) → (1,0) → (1,1) → (0,1) → (0,0)
```

#### 🔧 **Dosyalar**
- `tsp/tsp.c` - Implementation
- `tsp/tsp.txt` - Detailed explanation
- `tsp/square.txt` - Test case

---

## 🚀 Kurulum

### 📋 **Ön Gereksinimler**

![GCC](https://img.shields.io/badge/GCC-Required-red?style=flat-square&logo=gnu&logoColor=white)
![Make](https://img.shields.io/badge/CC-Optional-blue?style=flat-square&logo=gnu&logoColor=white)
![Math](https://img.shields.io/badge/Math%20Library-libm-green?style=flat-square)

<img align="right" alt="Algorithm Animation" width="300" src="https://media.giphy.com/media/v1.Y2lkPTc5MGI3NjExZmM0cG80aTJ4aDdrMXg5aml4bjhzcHJvdDNydHVpbHJkbXBrZzM4NyZlcD12MV9naWZzX3NlYXJjaCZjdD1n/8nTNSAyWSgfmpFZGkp/giphy.gif">

- **C Compiler**: `gcc` veya `cc`
- **Unix-like System**: Linux, macOS, WSL
- **Math Library**: `-lm` flag (TSP için)

### 📥 **Repository Klonlama**

```bash
# Repository'yi klonlayın
git clone https://github.com/skarayil/backtracking.git
cd backtracking
```

#### 🟡 **Toplu Derleme Script'i**

```bash
# Tüm programları derle
#!/bin/bash
for dir in floodfill permutations powerset n_queens rip tsp; do
    cd backtracking/$dir
    gcc -Wall -Werror -Wextra *.c -o $dir -lm
    echo "✅ $dir compiled"
done
```

---

## 📖 Öğrenme Yolu

### 🎯 **Önerilen Sıralama**

<div align="center">

```
🔰 Başlangıç
    ↓
1. Flood Fill (2D Traversal)
    ↓
2. Permutations (Basic Backtracking)
    ↓
🔶 Orta Seviye
    ↓
3. Powerset (Binary Choice)
    ↓
4. N-Queens (Constraint Checking)
    ↓
🔥 İleri Seviye
    ↓
5. RIP (String Manipulation)
    ↓
6. TSP (Optimization)
```

</div>

### 📚 **Her Problem İçin Öğrenme Adımları**

#### 1️⃣ **Problemi Anla**
```
✅ Problem tanımını oku
✅ Input/output örneklerini incele
✅ Kısıtlamaları belirle
✅ Base case'i tanımla
```

#### 2️⃣ **Algoritma Tasarla**
```
✅ State'i modelle (ne tutulacak?)
✅ Seçimleri belirle (ne denenecek?)
✅ Kısıtlamaları tanımla (ne geçerli?)
✅ Hedefi netleştir (ne zaman bitti?)
```

#### 3️⃣ **Implement Et**
```
✅ Base case'i yaz
✅ Recursive case'i yaz
✅ Constraint check ekle
✅ Backtracking adımını ekle
```

#### 4️⃣ **Test Et**
```
✅ Küçük input'larla test et
✅ Edge case'leri dene
✅ Output'u doğrula
✅ Complexity'i analiz et
```

---

## ⚡ **Common Pitfalls (Yaygın Hatalar)**

| Hata | Açıklama | Çözüm |
|------|----------|-------|
| **Backtrack Unutma** | Seçimi geri almamak | Her make_choice sonrası undo_choice |
| **Sonsuz Döngü** | Base case eksik | Her recursion'da base case kontrolü |
| **Memory Leak** | Malloc edilen bellek free edilmemiş | Her allocation için corresponding free |
| **Stack Overflow** | Çok derin recursion | Iterative çözüm veya pruning |
| **Duplicate Solutions** | Aynı çözümü birden fazla bulma | State tracking veya set kullanımı |

---

## 💡 Tips & Tricks

### 🎯 **Problem Çözme İpuçları**

#### 1️⃣ **Önce Küçük Düşün**
```
❌ "N=100 için çalışsın"
✅ "N=3 için çalışsın, sonra genelleştirelim"
```

#### 2️⃣ **Kağıt-Kalem Kullan**
```
📝 Decision tree çiz
📝 State transitions yaz
📝 Örnek input'u elle çöz
```

#### 3️⃣ **Debug İçin Print Ekle**
```c
void backtrack(int depth, ...) {
    // Debug: Mevcut durumu göster
    printf("Depth: %d, State: ...\n", depth);
    
    // ... backtracking logic
}
```

#### 4️⃣ **Base Case'i İyi Düşün**
```c
// ❌ Kötü base case
if (index == n)  // Peki index > n olursa?

// ✅ İyi base case  
if (index >= n || other_condition)
```

#### 5️⃣ **Constraint Check Önce**
```c
// ✅ Efficient
if (!is_valid(choice))
    continue;  // Erkeden kes

make_choice();
backtrack();
```

---
<div align="center">
  
### 👨‍💻 Created by Sude Naz Karayıldırım

[![42 Profile](https://img.shields.io/badge/42%20Profile-skarayil-black?style=flat-square&logo=42&logoColor=white)](https://profile.intra.42.fr/users/skarayil)
[![GitHub](https://img.shields.io/badge/GitHub-skarayil-181717?style=flat-square&logo=github&logoColor=white)](https://github.com/skarayil)

**⭐ Eğer bu proje işinize yaradıysa, repo'ya star vermeyi unutmayın!**

</div>

