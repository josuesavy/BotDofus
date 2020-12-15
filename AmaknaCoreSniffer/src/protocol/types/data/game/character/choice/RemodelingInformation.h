#ifndef REMODELINGINFORMATION_H
#define REMODELINGINFORMATION_H

#include "src/protocol/types/AbstractClass.h"
#include "src/engines/io/network/utils/FuncTree.h"

class RemodelingInformation : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_RemodelingInformation(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_RemodelingInformation(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_RemodelingInformation(FuncTree tree);
  RemodelingInformation();
  bool operator==(const RemodelingInformation &compared);

  QString name;
  int breed;
  bool sex;
  uint cosmeticId;
  QList<int> colors;

private:
  void _nameFunc(Reader *input);
  void _breedFunc(Reader *input);
  void _sexFunc(Reader *input);
  void _cosmeticIdFunc(Reader *input);
  void _colorstreeFunc(Reader *input);
  void _colorsFunc(Reader *input);

  FuncTree _colorstree;
};

#endif // REMODELINGINFORMATION_H