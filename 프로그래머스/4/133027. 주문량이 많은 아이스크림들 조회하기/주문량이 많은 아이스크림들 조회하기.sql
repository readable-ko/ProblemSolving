-- 코드를 입력하세요
# First_Half 맛(flavor가 pk), shipment_id (fk), total_order 총주문량
# JULY shipment(pk), flavor(fk), 같은 아이스크림이라도 다른 shipment_id일 수 있음.
# aa
WITH JF AS (
    SELECT FLAVOR, SUM(TOTAL_ORDER) as TOTAL_ORDER FROM JULY GROUP BY FLAVOR
)

SELECT F.FLAVOR FROM FIRST_HALF F JOIN JF ON F.FLAVOR = JF.FLAVOR GROUP BY FLAVOR ORDER BY SUM(F.TOTAL_ORDER + JF.TOTAL_ORDER) DESC LIMIT 3;