
try:
    f = open("orders.txt", 'r+')
    products = []
    for line in f.readlines():
        line = line.split()
        products.append(
            {"name":line[0],
            "amount":int(line[1]),
            "price":float(line[2])}
        )
    total, biggest, smallest = 0, float('-inf'), float('inf')

    for item in products:
        order = float(item["price"] * item["amount"])
        total += order
        if order > biggest:
            biggest = order
        if order < smallest:
            smallest = order
    print(f"{total:.2f}")
    print(f"{biggest:.2f}")
    print(f"{smallest:.2f}")
except BaseException as e:
    print(e)