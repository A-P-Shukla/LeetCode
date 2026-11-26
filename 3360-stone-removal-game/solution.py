class Solution:
    def stoneGame(self, n: int) -> bool:
        """
        Simulate the forced decreasing removal sequence.
        Return True if Alice (the first player) wins.
        """
        required = 10          # stones required for the current move
        alice_turn = True      # True -> Alice's move, False -> Bob's move

        while required > 0 and n >= required:
            n -= required
            required -= 1
            alice_turn = not alice_turn

        # If it's Alice's turn and she cannot move, she loses.
        # Otherwise Bob cannot move and Alice wins.
        return not alice_turn