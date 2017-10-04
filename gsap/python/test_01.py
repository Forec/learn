"""This is a test module for linking Python & CPP"""

print "Hello"

def mul(number1, number2):
    """calculate N!/M!"""
    def factorial(param):
        """calculate N!"""
        if param == 0:
            return 1
        return param * factorial(param-1)
    return factorial(number1) / factorial(number2)


def pstr(string="Hello, CPython", time=5):
    """print a string for several times"""
    import HostAPI
    print "PrintStaff was called from Python, calling RepeatString from CPP"
    HostAPI.RepeatString(string, time)
