def parser():
    while 1:
        data = list(input().split(' '))
        for number in data:
            if len(number) > 0:
                yield(number)   

input_parser = parser()

def get_word():
    global input_parser
    return next(input_parser)

def get_number():
    data = get_word()
    try:
        return int(data)
    except ValueError:
        return float(data)

count, kase = get_number(), 1

while kase <= count:
    a, b, c = get_number(), get_number(), get_number()
    print("Case #{}: {}".format(kase, 'true' if a+b>c else 'false'))
    kase = kase + 1
