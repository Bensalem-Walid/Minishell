# build/build.py
import sys

def print_progress(file, current, total):
    progress = (current / total) * 100
    bar_length = 50
    filled_length = int(bar_length * current // total)

    # Définir les couleurs
    red = '\033[91m'
    yellow = '\033[93m'
    green = '\033[92m'
    reset = '\033[0m'

    # Choisir la couleur en fonction de la progression
    if progress < 50:
        color = red
    elif progress < 80:
        color = yellow
    else:
        color = green

    bar = color + '█' * filled_length + reset + '-' * (bar_length - filled_length)
    sys.stdout.write(f'\rCompiling {file} [{bar}] {progress:.1f}%')
    sys.stdout.flush()

if __name__ == "__main__":
    filename = sys.argv[1]
    current_count = int(sys.argv[2])
    total_count = int(sys.argv[3])
    print_progress(filename, current_count, total_count)
