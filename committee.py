def factorial(num):
    if num<0:
        raise ValueError("People count must be positive.")
    result = 1 
    for i in range(1, num+1):
        result = result*i
    return result 
    
def committee(people, members, chairperson=True):
    if members>people:
        raise ValueError("Member count must not be greater than people count")
    result =1 
    if chairperson:
        result = factorial(people)/(factorial(members-1)*factorial(people-members))
    else:
        result = factorial(people)/(factorial(members)*factorial(people-members))
    return result