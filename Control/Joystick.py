import pygame

#Define some colors 
color_1 = (0, 0, 0)
color_2 = (0, 150, 0)

#This is a simple class that will help you print to the screen 
#it has nothing to do with the joysticks, just outputting 
#information

class TextPrint:
    def __init__(self):
        self.reset()
        self.font = pygame.font.Font(None, 20)

    def print(self, screen, textString):
        textBitmap = self.font.render(textString, True, color_2)
        screen.blit(textBitmap, [self.x, self.y])
        self.y += self.line_height

    def reset(self):
        self.x = 10
        self.y = 10
        self.line_height = 15

    def indent(self):
        self.x += 10

    def unindent(self):
        self.x -= 10

pygame.init()

#set the width and height of the screen [width, height]
size = [300,400]
screen = pygame.display.set_mode(size)
pygame.display.set_caption("JoyStick")

#Loop until the user clicks the close button 
done = False 

#Used to manage how fast the screen updates 
clock = pygame.time.Clock()

#Initialize the joystick
pygame.joystick.init()

#Get ready to print 
textPrint = TextPrint()

# ------------- Main Program Loop -------------
while done==False:
    #Event Processing Step
    for event in pygame.event.get(): #user did something 

        if event.type == pygame.QUIT: #if user clicked close 
            done = True

        # Possible Joystick Actions:
        #JOYAXISMOTION
        #JOYBALLMOTION
        #JOYBUTTONDOWN
        #JOYBUTTONUP
        #JOYHATMOTION

        if event.type == pygame.JOYBUTTONDOWN:
            print("JoyStick Button-Down Pressed.")
        if event.type == pygame.JOYBUTTONUP:
            print("JoyStick Button-Up Pressed.")

    #Drawing step
    #First, clear the screen to white. Don't put other drawing commands
    #Above this, or they will be erased with this command 
    screen.fill(color_1)
    textPrint.reset()

    #Get count of joysticks
    joysticks_count = pygame.joystick.get_count()

    textPrint.print(screen, "Number Of JoySticks: {}".format(joysticks_count))
    textPrint.indent()

    #For this JoyStick:
    joystick = pygame.joystick.Joystick(0)
    joystick.init()

    textPrint.print(screen, "Joystick ==> 1")
    textPrint.indent()

    #Get the name from the OS for the controller
    name = joystick.get_name()
    textPrint.print(screen, "JoyStick Name {}".format(name))

    #Usually axis run in pairs:
    #Up/Down
    #Left/Right 
    #ClockWise/anti-ClockWise
    axes = joystick.get_numaxes()
    textPrint.print(screen, "Number of Axes: {}".format(axes))
    textPrint.indent()

    for i in range(axes):
        axis = joystick.get_axis(i)
        textPrint.print(screen, "Axis {} value: {:>6.0f}".format(i, axis))
    textPrint.unindent()

    buttons = joystick.get_numbuttons()
    textPrint.print(screen, "Number of Buttons: {}".format(buttons))
    textPrint.indent()

    for i in range(buttons):
        button = joystick.get_button(i)
        textPrint.print(screen, "Button {:>2} value: {}".format(i+1, button))
    textPrint.unindent()

    #Hat switch. ALL or nothing for direction, not like joysticks.
    #value comes back in an array
    hats = joystick.get_numhats()
    textPrint.print(screen, "Number of Hats: {}".format(hats))
    textPrint.indent()

    for i in range(hats):
        hat = joystick.get_hat(i)
        textPrint.print(screen, "Hat {} value: {}".format(i, str(hat)))
    textPrint.unindent()

    textPrint.unindent()

    #All code to draw should go above this comment:

    #Go ahead and update the screen with what we've drawn
    pygame.display.flip()

    #Limit to frames per second 
    clock.tick(20)

#Close the window and quit.
#If you forget this line, the program will 'hang'
#on exit if running from IDLE 
pygame.quit()