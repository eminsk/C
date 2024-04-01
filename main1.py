left_boundary = int(input() or 0)
right_boundary = int(input() or 0)

numbers = []
while True:
    num_input = input()
    if num_input == '':
        break
    num = int(num_input)
    if num == 0 or num < left_boundary or num > right_boundary:
        print(False)
        break
    numbers.append(num)

if all(left_boundary < num < right_boundary for num in numbers):
    print(True)
else:
    print(False)