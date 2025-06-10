import tkinter as tk
import random
import string

# === CONFIG ===
TARGET = "Hello, world!"
POPULATION_SIZE = 200
MUTATION_RATE = 0.01
CHARS = string.ascii_letters + " .,!'?"
GENE_LENGTH = len(TARGET)


# === ALG GENETIC ===
def random_gene():
    return ''.join(random.choice(CHARS) for _ in range(GENE_LENGTH))


def fitness(gene):
    return sum(1 for a, b in zip(gene, TARGET) if a == b) / GENE_LENGTH


def mutate(gene):
    return ''.join(
        c if random.random() > MUTATION_RATE else random.choice(CHARS)
        for c in gene
    )


def crossover(parent1, parent2):
    mid = random.randint(0, GENE_LENGTH - 1)
    return mutate(parent1[:mid] + parent2[mid:])


# === GUI ===
class GeneticApp:
    def __init__(self, root):
        self.root = root
        self.root.title("Target String - Genetic Algorithm")

        self.generation = 0
        self.population = [random_gene() for _ in range(POPULATION_SIZE)]

        # UI Elements
        tk.Label(root, text="Target:").grid(row=0, column=0, sticky="w")
        self.target_label = tk.Label(root, text=TARGET, font=("Courier", 14, "bold"))
        self.target_label.grid(row=0, column=1, sticky="w")

        tk.Label(root, text="Generation:").grid(row=1, column=0, sticky="w")
        self.generation_label = tk.Label(root, text="0")
        self.generation_label.grid(row=1, column=1, sticky="w")

        tk.Label(root, text="Best Match:").grid(row=2, column=0, sticky="w")
        self.best_label = tk.Label(root, text="", font=("Courier", 14))
        self.best_label.grid(row=2, column=1, sticky="w")

        tk.Label(root, text="Fitness:").grid(row=3, column=0, sticky="w")
        self.fitness_label = tk.Label(root, text="0%")
        self.fitness_label.grid(row=3, column=1, sticky="w")

        self.start_evolution()

    def start_evolution(self):
        self.root.after(50, self.evolve_step)

    def evolve_step(self):
        self.generation += 1
        scored = [(gene, fitness(gene)) for gene in self.population]
        scored.sort(key=lambda x: -x[1])
        best_gene, best_fit = scored[0]

        self.generation_label.config(text=str(self.generation))
        self.best_label.config(text=best_gene)
        self.fitness_label.config(text=f"{best_fit * 100:.2f}%")

        if best_gene == TARGET:
            self.best_label.config(fg="green")
            return  # Gata!
        else:
            # Reproducere: top 20%
            parents = [gene for gene, _ in scored[:POPULATION_SIZE // 5]]
            self.population = [
                crossover(random.choice(parents), random.choice(parents))
                for _ in range(POPULATION_SIZE)
            ]
            self.root.after(30, self.evolve_step)


# === RUN ===
if __name__ == "__main__":
    root = tk.Tk()
    app = GeneticApp(root)
    root.mainloop()
