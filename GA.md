# Algoritmii Genetici - Explicație Completă

## 1. Conceptul de Bază

Algoritmii genetici sunt o tehnică de optimizare inspirată din evoluția biologică. Simulează procesele naturale de selecție, reproducere și mutație pentru a găsi soluții optime la probleme complexe.

**Principiile fundamentale:**
- **Populația** = colecție de soluții candidate (indivizi/cromozomi)
- **Fitness** = cât de bună este o soluție
- **Selecția** = părinții cu fitness mai bun au mai multe șanse să se reproducă
- **Crossover** = combinarea genelor de la doi părinți
- **Mutația** = schimbări aleatorii pentru diversitate
- **Evoluția** = populațiile se îmbunătățesc generație după generație

## 2. Structura Algoritmului

```
1. INIȚIALIZARE
   ↓
2. EVALUARE (calculează fitness)
   ↓
3. SELECȚIE (alege părinții)
   ↓
4. CROSSOVER (creează copiii)
   ↓
5. MUTAȚIE (introduce variație)
   ↓
6. ÎNLOCUIRE (noua generație)
   ↓
7. REPETĂ până la convergență
```

## 3. Exemple Concrete pentru TARGET = "HELLO"

### Pas 1: Inițializarea Populației
```
Generația 0 (populație inițială aleatoare):
Individ 1: "XMQPR" (fitness: 0/5)
Individ 2: "HZLTO" (fitness: 2/5) ← H și L corecte
Individ 3: "AELLO" (fitness: 4/5) ← E,L,L,O corecte
Individ 4: "KFJWM" (fitness: 0/5)
Individ 5: "HELKO" (fitness: 4/5) ← H,E,L,O corecte
...
```

### Pas 2: Evaluarea Fitness-ului
```python
def fitness(individual):
    return sum(1 for i, c in enumerate(individual) if c == TARGET[i])

# Exemple:
fitness("XMQPR") = 0  # niciun caracter corect în poziția corectă
fitness("HZLTO") = 2  # H pe poziția 0, L pe poziția 2
fitness("AELLO") = 4  # E,L,L,O pe pozițiile 1,2,3,4
fitness("HELLO") = 5  # toate corecte = SOLUȚIE!
```

### Pas 3: Selecția
```
Sortare după fitness:
1. "AELLO" (fitness: 4) ← cel mai bun
2. "HELKO" (fitness: 4)
3. "HZLTO" (fitness: 2)
4. "XMQPR" (fitness: 0)
5. "KFJWM" (fitness: 0)

Selecție pentru reproducere:
- Indivizii cu fitness mai mare au șanse mai mari
- "AELLO" și "HELKO" vor fi aleși des ca părinți
```

### Pas 4: Crossover (Încrucișarea)
```
Părinți selectați:
Părinte 1: "AELLO"
Părinte 2: "HELKO"

Crossover cu punct unic (poziția 2):
Copil = "AE" + "LKO" = "AELKO"

Crossover uniform (aleatoriu pe fiecare poziție):
Poziția 0: A vs H → alege H
Poziția 1: E vs E → alege E  
Poziția 2: L vs L → alege L
Poziția 3: L vs K → alege L
Poziția 4: O vs O → alege O
Copil = "HELLO" ← SOLUȚIE GĂSITĂ!
```

### Pas 5: Mutația
```
Copil înainte de mutație: "AELKO"
Rata de mutație: 0.01 (1%)

Pentru fiecare caracter:
- Poziția 0: A → probabilitate 1% să devină alt caracter → rămâne A
- Poziția 1: E → probabilitate 1% să devină alt caracter → rămâne E
- Poziția 2: L → probabilitate 1% să devină alt caracter → rămâne L
- Poziția 3: K → probabilitate 1% să devină alt caracter → devine L
- Poziția 4: O → probabilitate 1% să devină alt caracter → rămâne O

Copil după mutație: "AELLO"
```

### Pas 6: Noua Generație
```
Generația 1:
- Păstrează cel mai bun din generația anterioară (elitism)
- Adaugă copiii rezultați din crossover și mutație
- Populația rămâne constantă (100 indivizi)

Generația 1 (exemple):
"AELLO" (fitness: 4) ← păstrat prin elitism
"HELLO" (fitness: 5) ← SOLUȚIE din crossover!
"HELKO" (fitness: 4) ← copil din crossover
"HALLO" (fitness: 4) ← copil cu mutație
...
```

## 4. Detalii Tehnice

### Tipuri de Selecție
```
1. SELECȚIE PROPORTIONATĂ (Roulette Wheel):
   - Probabilitatea = fitness_individ / suma_fitness_totală
   
2. SELECȚIE TOURNAMENT:
   - Alege aleatoriu K indivizi
   - Cel cu fitness cel mai bun câștigă
   
3. SELECȚIE RANG:
   - Sortează după fitness
   - Probabilitatea depinde de poziția în clasament
```

### Tipuri de Crossover
```
1. PUNCT UNIC:
   Părinte1: "HELLO"
   Părinte2: "WORLD"
   Punct: 2
   Copil: "HE" + "RLD" = "HERLD"

2. MULTIPUNCT:
   Părinte1: "HELLO"
   Părinte2: "WORLD"
   Puncte: 1, 3
   Copil: "H" + "OR" + "O" = "HORO"

3. UNIFORM:
   Pentru fiecare poziție, alege aleatoriu de la care părinte
```

### Tipuri de Mutație
```
1. MUTAȚIE PUNCT:
   - Schimbă aleatoriu caractere individuale
   
2. MUTAȚIE SWAP:
   - Interschimbă două poziții
   
3. MUTAȚIE INVERSIE:
   - Inversează o secțiune din cromozom
```

## 5. Parametrii Importanți

### Dimensiunea Populației
```
- Prea mică (10-20): Convergență rapidă dar în optim local
- Optimă (50-200): Echilibru între explorare și exploatare  
- Prea mare (1000+): Convergență lentă, resurse multe
```

### Rata de Mutație
```
- Prea mică (0.001): Diversitate insuficientă, blocaje
- Optimă (0.01-0.1): Explorare echilibrată
- Prea mare (0.5+): Comportament aleatoriu, nu evoluție
```

### Strategii de Elitism
```
- Fără elitism: Risc de pierdere a celui mai bun individ
- Elitism moderat (1-5%): Păstrează progresul
- Elitism excesiv (20%+): Convergență prematură
```

## 6. Avantaje și Dezavantaje

### ✅ Avantaje
- Nu necesită informații despre gradientul funcției
- Funcționează cu spații de căutare discrete
- Explorează multiple soluții simultan
- Robust la optimi locali
- Paralelizabil natural

### ❌ Dezavantaje
- Nu garantează soluția optimă
- Convergență lentă pentru probleme mari
- Mulți parametri de reglat
- Poate converge prematur
- Necesită evaluări multe ale funcției fitness

## 7. Variante și Îmbunătățiri

### Algoritmi Genetici Adaptivi
- Parametrii se schimbă în timpul execuției
- Rata de mutație se adaptează la diversitatea populației

### Algoritmi Genetici Multi-Obiectiv
- Optimizează mai multe criterii simultan
- Folosesc conceptul de dominanță Pareto

### Algoritmi Genetici Hibride
- Combină cu alte tehnici (hill climbing, simulated annealing)
- Operatori specifici problemei

## 8. Aplicații Practice

### Probleme de Optimizare
- Rutarea vehiculelor
- Planificarea producției  
- Design de circuite
- Portofolii de investiții

### Inteligența Artificială
- Antrenarea rețelelor neuronale
- Evoluția comportamentelor în robotică
- Optimizarea hiperparametrilor

### Arte și Design
- Generarea muzicii
- Evoluția formelor artistice
- Design procedural în jocuri

## 9. Pseudocod Complet

```
ALGORITM_GENETIC(dimensiune_populație, generații_max):
    
    // 1. Inițializare
    populație = generează_populație_aleatoare(dimensiune_populație)
    generația = 0
    
    WHILE generația < generații_max AND nu_s-a_găsit_soluția:
        
        // 2. Evaluare
        PENTRU fiecare individ în populație:
            individ.fitness = calculează_fitness(individ)
        
        // 3. Verificare convergență
        cel_mai_bun = individ_cu_fitness_maxim(populație)
        DACĂ cel_mai_bun satisface criteriul de oprire:
            RETURN cel_mai_bun
        
        // 4. Selecție și Reproducere
        noua_populație = []
        
        // Elitism
        noua_populație.adaugă(cei_mai_buni(populație, numărul_elită))
        
        // Generează restul populației
        WHILE dimensiunea(noua_populația) < dimensiune_populație:
            
            // Selecție
            părinte1 = selecție(populație)
            părinte2 = selecție(populație)
            
            // Crossover
            copil = crossover(părinte1, părinte2)
            
            // Mutație
            copil = mutație(copil, rata_mutație)
            
            noua_populația.adaugă(copil)
        
        // 5. Înlocuire
        populație = noua_populație
        generația = generația + 1
    
    RETURN cel_mai_bun_individ(populație)
```

## 10. Sfaturi pentru Implementare

### Debugging și Monitoring
```python
# Urmărește statistici importante
print(f"Gen {gen}: Cel mai bun: {best} (fitness: {fitness(best)})")
print(f"Fitness mediu: {sum(fitness(ind) for ind in pop) / len(pop)}")
print(f"Diversitate: {len(set(pop))}")
```

### Optimizări de Performanță
```python
# Calculează fitness-ul o singură dată
population_fitness = [(ind, fitness(ind)) for ind in population]
population_fitness.sort(key=lambda x: x[1], reverse=True)

# Reutilizează evaluările pentru părinți în generația următoare
```

### Experimentare și Tuning
```python
# Testează cu parametri diferiți
parametri = [
    {'pop_size': 50, 'mutation_rate': 0.01},
    {'pop_size': 100, 'mutation_rate': 0.05},
    {'pop_size': 200, 'mutation_rate': 0.1}
]

for param in parametri:
    rezultat = rulează_ga(**param)
    print(f"Parametri {param}: {rezultat} generații")
```

Algoritmii genetici sunt o unealtă puternică și flexibilă pentru rezolvarea problemelor de optimizare complexe, fiind deosebit de utili când metodele tradiționale nu funcționează sau când spațiul de căutare este prea mare pentru explorarea exhaustivă.
