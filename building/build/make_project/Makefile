include ./config.mk

.PHONY:all
all: app

include $(modules_dir)/hello/build_moudle_hello.mk

app: $(modules) main
	@echo "开始链接生成: "$@
	$(CXX) $(wildcard $(output_dir)/*.o) -o $@
	@echo "成功生成: "$@

main: $(wildcard $(src_dir)/*.cpp)
	@echo "开始编译: "$@
	$(CXX) -c $(CXXFLAGS) $^ -o $(output_dir)/$@.o
	@echo $@"编译完成"

.PHONY:clean
clean:
	rm app output/*
