matrix = [['K', 'X', 'J', 'E', 'Y'],
          ['U', 'R', 'E', 'B', 'Z'],
          ['W', 'H', 'R', 'Y', 'T'],
          ['U', 'H', 'E', 'Y', 'F'],
          ['S', 'K', 'R', 'E', 'G']]
def playfair_decode(message):
    message = message.replace(' ', '')
    plaintext = ''
    for i in range(0, len(message), 2):
        a = message[i]
        b = message[i+1]
        a_row, a_col = 0, 0
        b_row, b_col = 0, 0
        for row in range(len(matrix)):
            if a in matrix[row]:
                a_row = row
                a_col = matrix[row].index(a)
            if b in matrix[row]:
                b_row = row
                b_col = matrix[row].index(b)
        if a_row == b_row:
            plaintext += matrix[a_row][(a_col-1)%5]
            plaintext += matrix[b_row][(b_col-1)%5]
        elif a_col == b_col:
            plaintext += matrix[(a_row-1)%5][a_col]
            plaintext += matrix[(b_row-1)%5][b_col]
        else:
            plaintext += matrix[a_row][b_col]
            plaintext += matrix[b_row][a_col]
    return plaintext
message = 'KXJEY UREBE ZWEHE WRYTU HEYFS KREHE GOYFI WTTTU OLKSY CAJPO BOTEI ZONTX BYBNT GONEY CUZWR GDSON SXBOU YWRHE BAAHY USEDQ'
plaintext = playfair_decode(message)
print(plaintext)
