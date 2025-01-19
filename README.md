# GitHashingExercise
Exercise for the course of Operating Systems at ECE AUTH

---

### `hash_script.sh` functionality

This Bash script generates or accepts a 4-digit integer (*if no input is provided, a random 4-digit integer is generated*), computes its SHA-256 hash, and logs it to the file `hash_output.txt` ***if it doesn’t already exist***, ensuring that no duplicate entries for the same input.

---

### Example Output

#### Case 1: No input provided
```
No input provided. Randomly generated 4-digit integer: 1234
Input: 1234
Hash:  03ac674216f3e15c761ee1a5e255f067953623c8b388b4459e13f978d7c846f4
The hash saved in hash_output.txt
```

#### Case 2: Duplicate input
```
Input: 1234
Hash:  03ac674216f3e15c761ee1a5e255f067953623c8b388b4459e13f978d7c846f4
Hash of 1234 already exists in hash_output.txt. No changes made.
```

---

### How to Call the Script

1. **Make the script executable**:
   ```bash
   chmod +x hash_script.sh
   ```

2. **Run without arguments** (*generates a random 4-digit integer to calculate its hash*):
   ```bash
   ./hash_script.sh
   ```

3. **Run with a specific 4-digit integer**:
   ```bash
   ./hash_script.sh 1234
   ```

This will either add the hash to `hash_output.txt` or notify you if it already exists.

> ***Note:*** *To validate the correctness of the output hash you can visit [this](https://www.lambdatest.com/free-online-tools/sha256-hash-calculator) site.*

