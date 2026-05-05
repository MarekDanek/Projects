import pygame
import math
from car import Car
import settings
import sys

pygame.init()
screen = pygame.display.set_mode((settings.width, settings.height))
clock = pygame.time.Clock() # Tohle ti pohlídá rychlost (FPS)

bg = pygame.image.load('trat.png')
my_car = Car()

while True:
    # 1. Eventy (zavření okna)
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()

    # 2. Ovládání a Update
    keys = pygame.key.get_pressed()
    if keys[pygame.K_LEFT]:
        my_car.angle += 5
    if keys[pygame.K_RIGHT]:
        my_car.angle -= 5
    my_car.update()

    # 3. Kreslení pozadí (neviditelný buffer)
    screen.blit(bg, (0, 0))

    # 4. Detekce kolize (díváme se na pozadí, než tam nakreslíme auto!)
    try:
        pixel_color = screen.get_at((int(my_car.x), int(my_car.y)))
        if pixel_color[0] == 0 and pixel_color[1] == 0 and pixel_color[2] == 0:
            print("NÁRAZ!")
            my_car.x = settings.x # Pozor na jména v settings.py!
            my_car.y = settings.y
            my_car.angle = settings.angle
            my_car.is_alive = False
    except IndexError:
        # Reset při vyjetí z okna
        my_car.x = settings.x
        my_car.y = settings.y

    # 5. Kreslení auta (pořád do neviditelného bufferu)
    my_car.draw(screen)

    # 6. FINÁLE: Teď to všechno najednou ukážeme na monitoru
    pygame.display.flip()

    # 7. Čekání na další snímek
    clock.tick(60)


