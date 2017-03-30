size = 100000
array = []

puts Time.now
1.upto(size) do |i|
	array << i
end

symbols_and_numbers = ['a'..'z','A'..'Z','0'..'9'].map{ |range| range.to_a }.flatten
symbols = ['a'..'z','A'..'Z'].map{ |range| range.to_a }.flatten
numbers = ['0'..'9'].map{ |range| range.to_a }.flatten
string = ""

size.times do |i|
	number = array.delete_at(rand(array.size)).to_s
	string += (0...32).map{ symbols_and_numbers[rand(symbols_and_numbers.size)] }.join + number + (0...(8 - number.size)).map{ symbols[rand(symbols.size)] }.join + "\n"
end

File.open('file.txt', 'w'){ |file| file.write string }
puts "Файл записан"

puts Time.now
