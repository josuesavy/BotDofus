#ifndef MAPCOORDINATES_H
#define MAPCOORDINATES_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/utils/io/type/FuncTree.h"

class MapCoordinates : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_MapCoordinates(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_MapCoordinates(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_MapCoordinates(FuncTree tree);
  MapCoordinates();
  bool operator==(const MapCoordinates &compared);

  int worldX;
  int worldY;

private:
  void _worldXFunc(Reader *input);
  void _worldYFunc(Reader *input);
};

#endif // MAPCOORDINATES_H