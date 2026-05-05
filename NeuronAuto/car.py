import pygame
import math
import settings

class Car:

    def __init__(self):
        self.width = settings.width
        self.height = settings.height
        self.x = settings.x
        self.y = settings.y
        self.white = settings.white
        self.black = settings.black
        self.red = settings.red
        self.angle = settings.angle
        self.speed = settings.speed

        self.is_alive = True


    def draw(self, screen):
        pygame.draw.rect(screen, (255, 0, 0), (self.x, self.y, 20, 10))

    def update(self):
        rad = math.radians(self.angle)
        self.x += math.cos(rad) * self.speed
        self.y -= math.sin(rad) * self.speed

    #def check_radar():

