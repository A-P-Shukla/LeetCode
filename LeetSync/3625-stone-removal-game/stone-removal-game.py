class Solution:
    def canAliceWin(self, n: int) -> bool:
        required = 10         
        alice_turn = True     

        while required > 0 and n >= required:
            n -= required
            required -= 1
            alice_turn = not alice_turn

        return not alice_turn