-- 코드를 입력하세요
SELECT left(product_code,2) as CATEGORY, count(*) as PRODUCTS
FROM product
group by category
order by category