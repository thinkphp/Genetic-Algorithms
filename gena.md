În contextul **algoritmilor genetici**, un **gen** reprezintă **cea mai mică unitate de informație** dintr-un cromozom (soluție candidată). El corespunde unei **componente specifice a soluției** reprezentate de cromozom.  

### Ce înseamnă practic:
1. **Analogia biologică**:  
   - La fel cum în biologie un **gen** codifică o trăsătură (ex: culoarea ochilor), în algoritmii genetici un **gen** stochează o parte a soluției (ex: o decizie, o valoare, un parametru).

2. **Structura cromozomului**:  
   - Un cromozom = o secvență de **gene** (ca un șir de ADN).  
   - *Exemplu*:  
     - Problemă de optimizare cu 4 variabile: `[x₁, x₂, x₃, x₄]` → fiecare `x_i` este un **gen**.  
     - Problemă de permutare (TSP): `[oraș1, oraș2, oraș3]` → fiecare oraș este un **gen**.

3. **Reprezentare**:  
   - Genele pot fi:  
     - **Binare**: `0` sau `1` (ex: "include" sau "nu include" un obiect în rucsac).  
     - **Întregi**: valori discrete (ex: `3`, `5`, `2` într-o permutare).  
     - **Reale**: numere cu virgulă (ex: `2.71`, `-0.5` pentru parametri continui).  

### De ce sunt importante?
- **Operatorii genetici** (crossover, mutație) acționează pe **gene**:  
  - *Crossover*: combină gene din doi părinți.  
  - *Mutația*: modifică valori individuale ale genelor.  
- **Fitness-ul soluției** depinde de configurația genelor.  

---

### Exemplu concret:
Pentru problema comis-voiajor (**TSP**):  
- **Cromozom**: `[A, C, B, D]` (o rută posibilă).  
- **Genele sale**: fiecare oraș (`A`, `C`, `B`, `D`).  
- Dacă aplicăm o **mutație** (schimbăm două gene): obținem `[A, B, C, D]` → o nouă rută.  

---

### Concluzie:
Un **gen** este **o "bucată" a soluției** care, combinată cu alte gene, formează un cromozom complet. El este elementul de bază asupra căruia operează algoritmul genetic pentru a genera soluții îmbunătățite.
