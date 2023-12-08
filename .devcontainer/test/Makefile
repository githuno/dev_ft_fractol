# .PHONY: chop veggies cook assemble serve

all: serve

chop:
	@echo "Step 1: Chop the vegetables"
# .PHONYがなくファイル「chop」が存在するとき、make chopを実行しても何も処理しない。

veggies: chop
	@echo "Step 2: Prepare the vegetables"
# .PHONYがなくファイル「(自分より新しく作成された)veggies」が存在するとき、make veggiesを実行しても何も処理しない。
# ただし、ファイル「chop」が存在しないときには、chopもveggiesも実行される。

cook: veggies
	@echo "Step 3: Cook the ingredients"

assemble: cook
	@echo "Step 4: Assemble the dish"

serve: assemble
	@echo "Step 5: Serve the delicious dish"
