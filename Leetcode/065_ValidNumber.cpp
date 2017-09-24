import re

class Solution(object):
    def isNumber(self, s):
        """
        :type s: str
        :rtype: bool
        """
        
        # Regex for simple numbers (e.g. "123", " 123", "2342   ", "-123124")
        if re.match(r"^[\s]*[\-\+]?[0-9]+[\s]*$", s):
            return True
        
        # Regex for decimals (e.g. ".3", ".232", "-.123")
        if re.match(r"^[\s]*[\-\+]?[0-9]*\.[0-9]+[\s]*$", s):
            return True
        
        # Regex for decimals (e.g. "234.", "   4.", "+2343.")
        if re.match(r"^[\s]*[\-\+]?[0-9]+\.[0-9]*[\s]*$", s):
            return True
        
        # Regex for exponentials
        if re.match(r"^[\s]*[\-\+]?[0-9]+[\.]?[0-9]*e[\-\+]?[0-9]+[\s]*$", s):
            return True
        
        # Regex for exponentials
        if re.match(r"^[\s]*[\-\+]?[0-9]*[\.]?[0-9]+e[\-\+]?[0-9]+[\s]*$", s):
            return True
        
        return False
        