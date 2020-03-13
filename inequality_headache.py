count = 0


def main():
    a = "s"
    # copy of a
    b = "s"

    c = "ss"
    # copy of c
    d = "ss"

    va = ["s"]
    vp = 0
    permutations(vp, b, d, va, a, c)
    print(count)


def permutations(vp, b, d, va, a, c):
    #print(f"index is {vp}")
    for i in range(1, 9+1):
        for ch in a:
            b = a.replace(va[vp], str(i))
        for ch in c:
            d = c.replace(va[vp], str(i))
        # print(f"{d}")
        # print(f"changing letters {b}")
        if vp < len(va) - 1:
            vp2 = vp
            vp2 += 1
            permutations(vp2, b, d, va, b)
        else:
            # perform inequality if
            # print(f"{b}", end=" < ")
            #print(f"{d}", end=" : ")
            global count
            if b < d:
                count += 1


main()
