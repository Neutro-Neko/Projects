
# class Engine:
#     def __init__(self, manufacturer = "toyota", model, year,horsepower):
#         self.manufacturer = manufacturer
class Vehicle:
    def __init__(self, brand, model, year):
        self.brand = brand
        self.model = model
        self.year = year
    def description(self):
        return "brand: "+self.brand+" model: "+self.model+" year: "+str(self.year)


class Car(Vehicle):
    def __init__(self, brand ="Łada", model ="Łada", year = 1820, doors = 5, fuel ="petrol"):
        Vehicle.__init__(self, brand, model, year)
        self.doors = doors
        self.fuel = fuel
    def full_description(self):
        print(self.description()+" doors: "+str(self.doors)+" fuel: "+self.fuel)

class Motorcycle(Vehicle):
    def __init__(self, brand = "yamaha", model ="kamikaze", year = 2003, engine_volume_in_l = 1):
        Vehicle.__init__(self, brand, model, year)
        self.engine_volume_in_l = engine_volume_in_l
    def full_description(self):
        print(self.description()+" engine_volume_in_l: "+str(self.engine_volume_in_l))
def show_vehicles(vehicles):
    for vehicle in vehicles:
        vehicle.full_description()
def vehicles_of_brand(brand, vehicles):
    for vehicle in vehicles:
        if vehicle.brand == brand:
            vehicle.full_description()
vehicles = [Car(),Car("Uada","Uada"),Motorcycle()]
show_vehicles(vehicles)
print()
vehicles_of_brand("Łada", vehicles)
print()
vehicles_of_brand("yamaha", vehicles)
vehicles_of_brand()
