def lru(pages,frames):
    frame = []
    last_use = {}
    fault = 0


    for  i, p in enumerate(pages):
        if p not in frame:
            fault += 1
            if len(frame ) < frames:
                frame.append(p)
            else:
                lru_page = min(frame, key=lambda x: last_use[x])
                frame[frame.index(lru_page)] = p
            
        last_use[p] = i

    return fault

pages = [7,0,1,2,0,3,0,4,2,3,0,3,0,3,2,1,2,0,1,7,0,1]
frames = 3

print(lru(pages, frames))