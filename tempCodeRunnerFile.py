def plot(s):
    for i, x in enumerate(s):
        plt.barh(0, x.end-x.start, left=x.start)
        plt.text((x.start+x.end)/2, 0, f"P{x.pid}", ha='center')
    plt.xticks(range(min(x.start for x in s), max(x.end for x in s)+1))
    plt.show()