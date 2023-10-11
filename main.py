import pygame
pygame.init()

screen = pygame.display.set_mode((700, 500))
pygame.display.set_caption("Pong")

doExit = False

clock = pygame.time.Clock()

p1x = 20
p1y = 200

p2x = 660
p2y = 200

bx = 300
by = 200

bVx = 5
bVy = 5

p1Score = 0
p2Score = 0

while not  doExit: #game loop
    
    clock.tick(60)
    
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            doExit = True
            
#game logic will go here---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
   #paddles
    keys = pygame.key.get_pressed()
    if keys[pygame.K_w]:
        p1y-=8
    if keys[pygame.K_s]:
        p1y+=8
        
    keys = pygame.key.get_pressed()
    if keys[pygame.K_UP]:
        p2y-=8
    if keys[pygame.K_DOWN]:
        p2y+=8
        
        #ball
    bx += bVx
    by += bVy
        
    #ball hits left or right wall
    if bx + 20 > 700:
            bVx *= -1
            
    if by + 20 < 700:
            bVy *= -1
            #increase p1 score here
            
    #ball hits right paddle
    if bx < p1x + 20 and by + 20 > p1y and by < p1y + 100:
                bVx *= -1
     #ball hits left paddle           
    if bx > p2x and by + 20 > p2y and by < p2y + 100:
                bVx *= -1
    #print(p1x, p1y, p2x, p2y)
        
    #increase score when you hit the left wall
    if bx <700:
                bVx*= -1
                p1Score += 1
    
    if bx > 0:
                bVx*= -1
                p2Score += 1
                
#render section will go here----------------------------------------------------------------------------------------------------------------------------------------------------------------------
    screen.fill((0,0,0,))
    #paddle
    pygame.draw.line(screen, (255, 255, 255), [349, 0], [349, 500], 5)
    
    pygame.draw.rect(screen, (255, 255, 255), (p1x, p1y, 20, 100), 1)
    
    pygame.draw.rect(screen, (255, 255, 255), (p2x, p2y, 20, 100), 1)
    
    pygame.draw.circle(screen, (255, 255, 255),  (bx, by), 10)
    
    pygame.display.flip()
        
    font = pygame.font.Font(None, 74)
    text = font.render(str(p1Score), 1, (255, 255, 255))
    screen.blit(text, (250,10))
    text = font.render(str(p2Score), 1, (255, 255, 255))
    screen.blit(text, (420,10))
            
#end of game loop      
pygame.quit()

