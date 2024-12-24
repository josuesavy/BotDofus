#ifndef PADDOCKINFORMATIONSFORSELL_H
#define PADDOCKINFORMATIONSFORSELL_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/utils/io/type/FuncTree.h"

class PaddockInformationsForSell : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PaddockInformationsForSell(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PaddockInformationsForSell(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PaddockInformationsForSell(FuncTree tree);
  PaddockInformationsForSell();
  bool operator==(const PaddockInformationsForSell &compared);

  QString guildOwner;
  int worldX;
  int worldY;
  uint subAreaId;
  int nbMount;
  int nbObject;
  double price;

private:
  void _guildOwnerFunc(Reader *input);
  void _worldXFunc(Reader *input);
  void _worldYFunc(Reader *input);
  void _subAreaIdFunc(Reader *input);
  void _nbMountFunc(Reader *input);
  void _nbObjectFunc(Reader *input);
  void _priceFunc(Reader *input);
};

#endif // PADDOCKINFORMATIONSFORSELL_H