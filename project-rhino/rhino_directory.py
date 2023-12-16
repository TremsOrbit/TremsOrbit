"""

Rhinoceros Preservation
Tristin Houston
thousto2@uvm.edu


Sources:
https://www.sheldrickwildlifetrust.org,
https://www.savetherhino.org/rhino-info/population-figures/,
https://therhinoorphanage.org/

PIP INSTALL FOLIUM

"""


import json


rhino_data = []
total_population = 27431



def add_rhino(): # adds a rhino to the directory
    name = input("Enter rhinoceros name: ")
    DOB = input("Enter DOB (YYYY-MM-DD): ")
    location = input("Enter location/region: ")
    status = input("Enter preservation status: ")
    
    rhino = { # after you provide these four pieces of info *look down*
        "Name": name,
        "Date of Birth": DOB,
        "Region": location,
        "Status of Containment": status
    }
    
    rhino_data.append(rhino) #it spits out this message at you
    print("Rhinoceros added to the directory.")


def save_data():
    with open("rhino_data.json", "w") as file:
        json.dump(rhino_data, file)
    print("Data saved to the directory successfully.")

def load_data():
    try:
        with open("rhino_data.json", "r") as file:
            global rhino_data
            rhino_data = json.load(file)
        print("Data loaded...")
    except FileNotFoundError:
        print("No existing data file found.")

def display_rhino():
    if not rhino_data:
        print("No rhino records found.")
    else:
        for idx, rhino in enumerate(rhino_data):
            print(f"Record {idx}:")
            for key, value in rhino.items():
                print(f"{key}: {value}")
            print()

def remove_rhino():
    display_rhino()
    if not rhino_data:
        print("No records to remove.")
    else:
        try:
            idx_to_remove = int(input("Enter the list number of the rhino to remove: "))
            if 0 <= idx_to_remove < len(rhino_data):
                rhino_data.pop(idx_to_remove)
                print("Rhino record removed successfully.")
            else:
                print("Invalid list number.")
        except ValueError:
            print("Invalid input. Please enter a number.")
            
            
def display_population():
    global total_population
    print(f"Total number of rhinoceros in the population: {total_population}")
    


# Main Program Section - It's a loop
while True:
    print("\nRhinoceros Preservation Directory")
    print("1. Add a new rhinoceros record")
    print("2. Save data to the directory")
    print("3. Load data from the directory")
    print("4. Display all rhino records")
    print("5. Remove a rhino record")
    print("6. Display population and rhino records")
    print("7. Exit")

    choice = input("Enter your choice: ")


    if choice == "1":
        add_rhino()
        total_population += 1  # Increment population count when adding a rhino
    elif choice == "2":
        save_data()
    elif choice == "3":
        load_data()
    elif choice == "4":
        display_rhino()
    elif choice == "5":
        remove_rhino()
        total_population -= 1  # Decrement population count when removing a rhino
    elif choice == "6":
        display_population()
    elif choice == "7":
        print("Exiting the program.")
        break
    else:
        print("Invalid choice, try again.")