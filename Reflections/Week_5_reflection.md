## Accomplishments

I have successfully added in basic file I/O to my program.

It is imperfect, I am still not serializing all of the features of my lines as-is and more work will need to be done to support that, however I am happy with being able to save and load at all.

## Challenges

The biggest challenge so far has been in the fact that I could not find a in-built way in the C++ stdlib to write formatted binary output.

It would perhaps be easy to assume that the concept of formatted binary is meaningless, however that is far from the case. Among the considerations for binary output are the following:

- Endianess
- Byte width of specific elements (sizeof(int) is not specified)
- null termination for strings or length encoding?

This is not the entirety of the considerations, but is a sizable chunk.

The correct solution for this would have been to write my own implementation of the very complicated "streambuf" class, and reimplement the proper way to encode a variety of basic types. However I was lucky enough for Qt5 to provide the `QDataStream` which provides a platform agnostic solution to my worries.

## Next Steps

The file writing does not have all of the features it needs to support quite yet, and is still rather non-ergonomic. More work needs to be done.

## Resources

(A Google Groups Conversation)[https://groups.google.com/g/comp.std.c++/c/D4e0q9eVSoc]
(An incredible guide about the traps that come with iostreams)[https://gcc.gnu.org/onlinedocs/libstdc++/manual/fstreams.html]