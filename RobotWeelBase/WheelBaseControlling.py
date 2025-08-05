import serial
import time

ser = serial.Serial('/dev/ttyUSB0', 9600, timeout=1)
time.sleep(2) # Wait for serial connection to settleup

def send_command(command):
    ser.write(command.encode()) # Send command to Arduino
    time.sleep(0.1) 

try:
    while True:
        user_input = input("Enter command (F=Forward, B=Backward, L=Left, R=Right, S=Stop, Q=Quit): ").upper()
        if user_input == 'Q':
            break
        elif user_input in ['F', 'B', 'L', 'R', 'S']:
            send_command(user_input)
        else:
            print("Invalid command!")
except KeyboardInterrupt:
    print("Program terminated")
finally:
    ser.close() # Close serial connection
